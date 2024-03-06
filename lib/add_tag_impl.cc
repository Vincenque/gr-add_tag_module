/* -*- c++ -*- */
/*
 * Copyright 2024 Witold Duda.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "add_tag_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace add_tag_module {

using input_type = float;
using output_type = float;
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
                         1 /* min inputs */, 1 /* max inputs */, sizeof(input_type)),
                     gr::io_signature::make(
                         1 /* min outputs */, 1 /*max outputs */, sizeof(output_type)))
{
}

/*
 * Our virtual destructor.
 */
add_tag_impl::~add_tag_impl() {}

int add_tag_impl::work(int noutput_items,
                       gr_vector_const_void_star& input_items,
                       gr_vector_void_star& output_items)
{
    auto in = static_cast<const input_type*>(input_items[0]);
    auto out = static_cast<output_type*>(output_items[0]);
    out[0] = in[0];
    return noutput_items;
}

} /* namespace add_tag_module */
} /* namespace gr */
