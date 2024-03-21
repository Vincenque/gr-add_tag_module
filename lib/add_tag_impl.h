#ifndef INCLUDED_ADD_TAG_MODULE_ADD_TAG_IMPL_H
#define INCLUDED_ADD_TAG_MODULE_ADD_TAG_IMPL_H

#include <gnuradio/add_tag_module/add_tag.h>
#include <chrono>
#include <iostream>
#include <string>
using namespace std;

namespace gr {
namespace add_tag_module {

class add_tag_impl : public add_tag
{
private:
    size_t d_itemsize;
    bool d_burst;
    unsigned int d_num_ports;
    int samples_count;
    bool samples_recorded;
    int d_number_of_samples_to_record;
    bool recording;
    string d_filename;
    string d_previous_filename;
    int index_of_file;

public:
    add_tag_impl(size_t itemsize,
                 int num_ports,
                 bool burst,
                 int number_of_samples_to_record,
                 string filename);
    ~add_tag_impl();

    void set_burst(bool burst) override { d_burst = burst; }
    bool burst() const override { return d_burst; }

    void set_filename(string filename) override { d_filename = filename; }
    string filename() const override { return d_filename; }

    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace add_tag_module
} // namespace gr

#endif /* INCLUDED_ADD_TAG_MODULE_ADD_TAG_IMPL_H */
