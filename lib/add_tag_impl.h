#ifndef INCLUDED_ADD_TAG_MODULE_ADD_TAG_IMPL_H
#define INCLUDED_ADD_TAG_MODULE_ADD_TAG_IMPL_H

#include <gnuradio/add_tag_module/add_tag.h>
#include <chrono> // Include the chrono library

namespace gr {
namespace add_tag_module {

class add_tag_impl : public add_tag
{
private:
    size_t d_itemsize;
    bool d_burst;
    bool d_burst_state;
    unsigned int d_num_ports;

public:
    add_tag_impl(size_t itemsize, bool burst);
    ~add_tag_impl();

    void set_burst(bool burst) override
    {
        d_burst = burst;
    }
    bool burst() const override { return d_burst; }

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace add_tag_module
} // namespace gr

#endif /* INCLUDED_ADD_TAG_MODULE_ADD_TAG_IMPL_H */
