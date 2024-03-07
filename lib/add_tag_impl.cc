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
#include <chrono> // Include the chrono library

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
      d_burst_state(false),
      d_last_print_time(std::chrono::steady_clock::now()) // Initialize the last print time to the current time
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
    // Get the current time
    auto now = std::chrono::steady_clock::now();

    // Calculate the time difference since the last print
    auto time_diff = std::chrono::duration_cast<std::chrono::seconds>(now - d_last_print_time).count();

    // If at least one second has passed since the last print
    if (time_diff >= 1) {
        // Print the values of d_burst and d_burst_state to the console
        std::cout << "d_burst: " << d_burst << ", d_burst_state: " << d_burst_state << std::endl;

        // Get the current time in a human-readable format
        auto now_c = std::chrono::system_clock::now();
        std::time_t now_ct = std::chrono::system_clock::to_time_t(now_c);
        std::cout << "Current time: " << std::ctime(&now_ct) << std::endl;

        // Update the last print time
        d_last_print_time = now;
    }

    if (d_burst != d_burst_state) {
        d_burst_state = d_burst;
        pmt::pmt_t key = pmt::string_to_symbol("burst");
        pmt::pmt_t value = pmt::from_bool(d_burst_state);
        for (int i = 0; i < 4; ++i) {
            add_item_tag(i, nitems_written(i), key, value);
            auto in = static_cast<const input_type*>(input_items[i]);
            auto out = static_cast<output_type*>(output_items[i]);
            std::copy(in, in + noutput_items, out);
        }
    }
    return noutput_items;
}

} /* namespace add_tag_module */
} /* namespace gr */
