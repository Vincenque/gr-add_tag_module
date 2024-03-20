#ifndef INCLUDED_ADD_TAG_MODULE_ADD_TAG_H
#define INCLUDED_ADD_TAG_MODULE_ADD_TAG_H

#include <gnuradio/add_tag_module/api.h>
#include <gnuradio/sync_block.h>
#include <iostream>
#include <string>
using namespace std;

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
     * \param itemsize size of the input and output items
     * \param num_ports number of the input and output ports
     * \param burst The new burst state
     * \param number_of_samples_to_record Number of samples to record. If equal to 0 do
     * record when everything when button is pressed. \param filename Name of file used in
     * gr-modified_tagged_file_sink.
     */
    static sptr make(size_t itemsize,
                     int num_ports,
                     bool burst,
                     int number_of_samples_to_record,
                     string filename);


    /*!
     * \brief Set the burst state
     *
     * This method allows you to dynamically change the burst state of the block.
     *
     * \param burst The new burst state
     */
    virtual void set_burst(bool burst) = 0;
    virtual bool burst() const = 0;

    /*!
     * \brief Set the file name
     *
     * This method allows you to dynamically change the burst state of the block.
     *
     * \param filename The new filename
     */
    virtual void set_filename(string filename) = 0;
    virtual string filename() const = 0;
};

} // namespace add_tag_module
} // namespace gr

#endif /* INCLUDED_ADD_TAG_MODULE_ADD_TAG_H */
