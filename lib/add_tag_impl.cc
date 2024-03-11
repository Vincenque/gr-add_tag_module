/* -*- c++ -*- */
/*
 * Copyright 2024 Witold Duda.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "add_tag_impl.h"
#include <gnuradio/io_signature.h>
#include <pmt/pmt.h>
#include <iostream> // Include the iostream library

namespace gr {
namespace add_tag_module {

using input_type = gr_complex;
using output_type = gr_complex;
add_tag::sptr add_tag::make(bool burst)
{
    return gnuradio::make_block_sptr<add_tag_impl>(burst);
}


/*
 * The private constructor
 */
add_tag_impl::add_tag_impl(bool burst)
    : gr::sync_block("add_tag",
                     gr::io_signature::make(
                         4 /* min inputs */, 4 /* max inputs */, sizeof(input_type)),
                     gr::io_signature::make(
                         4 /* min outputs */, 4 /*max outputs */, sizeof(output_type))),
      d_burst(burst),
      d_burst_state(false)
{
    d_burst = burst;
}

/*
 * Our virtual destructor.
 */
add_tag_impl::~add_tag_impl() {}

int add_tag_impl::work(int noutput_items,
                       gr_vector_const_void_star& input_items,
                       gr_vector_void_star& output_items)
{
    if (d_burst != d_burst_state) {
        d_burst_state = d_burst;
        pmt::pmt_t key = pmt::string_to_symbol("burst");
        pmt::pmt_t value = pmt::from_bool(d_burst_state);
        for (int i = 0; i < 4; ++i) {
            add_item_tag(i, nitems_written(i), key, value);
        }
    }

    for (int i = 0; i < 4; ++i) {
        const input_type* in = static_cast<const input_type*>(input_items[i]);
        output_type* out = static_cast<output_type*>(output_items[i]);
        std::copy(in, in + noutput_items, out);
    }

    return noutput_items;
}


} /* namespace add_tag_module */
} /* namespace gr */
