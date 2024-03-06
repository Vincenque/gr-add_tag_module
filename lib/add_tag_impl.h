/* -*- c++ -*- */
/*
 * Copyright 2024 Witold Duda.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_ADD_TAG_MODULE_ADD_TAG_IMPL_H
#define INCLUDED_ADD_TAG_MODULE_ADD_TAG_IMPL_H

#include <gnuradio/add_tag_module/add_tag.h>

namespace gr {
namespace add_tag_module {

class add_tag_impl : public add_tag
{
private:
    bool d_burst;

public:
    add_tag_impl(bool burst);
    ~add_tag_impl();

    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace add_tag_module
} // namespace gr

#endif /* INCLUDED_ADD_TAG_MODULE_ADD_TAG_IMPL_H */
