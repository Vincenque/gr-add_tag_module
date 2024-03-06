/* -*- c++ -*- */
/*
 * Copyright 2024 Witold Duda.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_ADD_TAG_MODULE_ADD_TAG_H
#define INCLUDED_ADD_TAG_MODULE_ADD_TAG_H

#include <gnuradio/add_tag_module/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace add_tag_module {

/*!
 * \brief <+description of block+>
 * \ingroup add_tag_module
 *
 */
class ADD_TAG_MODULE_API add_tag : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<add_tag> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of add_tag_module::add_tag.
     *
     * To avoid accidental use of raw pointers, add_tag_module::add_tag's
     * constructor is in a private implementation
     * class. add_tag_module::add_tag::make is the public interface for
     * creating new instances.
     */
    static sptr make(bool burst = false);
};

} // namespace add_tag_module
} // namespace gr

#endif /* INCLUDED_ADD_TAG_MODULE_ADD_TAG_H */
