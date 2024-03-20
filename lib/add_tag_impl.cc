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
add_tag::sptr add_tag::make(size_t itemsize,
                            int num_ports,
                            bool burst,
                            int number_of_samples_to_record,
                            string filename)
{
    return gnuradio::make_block_sptr<add_tag_impl>(
        itemsize, num_ports, burst, number_of_samples_to_record, filename);
}

add_tag_impl::add_tag_impl(size_t itemsize,
                           int num_ports,
                           bool burst,
                           int number_of_samples_to_record,
                           string filename)
    : gr::sync_block("add_tag",
                     gr::io_signature::make(
                         1 /* min inputs */, -1 /* max inputs */, sizeof(input_type)),
                     gr::io_signature::make(
                         1 /* min outputs */, -1 /*max outputs */, sizeof(output_type))),
      d_burst(burst),
      d_num_ports(num_ports),
      samples_count(0),
      samples_recorded(false),
      d_number_of_samples_to_record(number_of_samples_to_record),
      recording(false),
      d_filename(filename),
      d_previous_filename(filename)
{
    d_burst = burst;
}

add_tag_impl::~add_tag_impl() {}

int add_tag_impl::work(int noutput_items,
                       gr_vector_const_void_star& input_items,
                       gr_vector_void_star& output_items)
{
    if (d_filename != d_previous_filename) {
        d_previous_filename = d_filename;
        std::cout << "Changed file name." << std::endl;
        recording = false;
        samples_count = 0;
        samples_recorded = false;
    }
    if (d_burst == true) {
        recording = true;
    }
    if (recording == true) {
        if (samples_count == 0) {
            std::cout << "Starting recording to file: " << d_filename << std::endl;
        }
        pmt::pmt_t key = pmt::string_to_symbol("burst");
        pmt::pmt_t value = pmt::from_bool(true);
        for (int i = 0; i < int(d_num_ports); ++i) {
            add_item_tag(i, nitems_written(i), key, value);
        }
    }


    if (recording == true) {
        samples_count += noutput_items + 1;
    }
    if (samples_count >= d_number_of_samples_to_record && samples_recorded == false) {
        std::cout << "Number of recorded samples:" << samples_count << std::endl;
        samples_recorded = true;
        pmt::pmt_t key = pmt::string_to_symbol("burst");
        pmt::pmt_t value = pmt::from_bool(false);
        for (int i = 0; i < int(d_num_ports); ++i) {
            add_item_tag(i, nitems_written(i), key, value);
        }
        recording = false;
        std::cout << "Recording ended." << std::endl << std::endl;
    }

    for (int i = 0; i < int(d_num_ports); ++i) {
        const input_type* in = static_cast<const input_type*>(input_items[i]);
        output_type* out = static_cast<output_type*>(output_items[i]);
        std::copy(in, in + noutput_items, out);
    }

    return noutput_items;
}


} /* namespace add_tag_module */
} /* namespace gr */
