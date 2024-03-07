#!/usr/bin/env python3
# -*- coding: utf-8 -*-

#
# SPDX-License-Identifier: GPL-3.0
#
# GNU Radio Python Flow Graph
# Title: Not titled yet
# GNU Radio version: 3.10.7.0

from packaging.version import Version as StrictVersion
from PyQt5 import Qt
from gnuradio import qtgui
from gnuradio import add_tag_module
from gnuradio import analog
from gnuradio import blocks
from gnuradio import eng_notation
from gnuradio import gr
from gnuradio.filter import firdes
from gnuradio.fft import window
import sys
import signal
from PyQt5 import Qt
from argparse import ArgumentParser
from gnuradio.eng_arg import eng_float, intx



class testTagModule(gr.top_block, Qt.QWidget):

    def __init__(self):
        gr.top_block.__init__(self, "Not titled yet", catch_exceptions=True)
        Qt.QWidget.__init__(self)
        self.setWindowTitle("Not titled yet")
        qtgui.util.check_set_qss()
        try:
            self.setWindowIcon(Qt.QIcon.fromTheme('gnuradio-grc'))
        except BaseException as exc:
            print(f"Qt GUI: Could not set Icon: {str(exc)}", file=sys.stderr)
        self.top_scroll_layout = Qt.QVBoxLayout()
        self.setLayout(self.top_scroll_layout)
        self.top_scroll = Qt.QScrollArea()
        self.top_scroll.setFrameStyle(Qt.QFrame.NoFrame)
        self.top_scroll_layout.addWidget(self.top_scroll)
        self.top_scroll.setWidgetResizable(True)
        self.top_widget = Qt.QWidget()
        self.top_scroll.setWidget(self.top_widget)
        self.top_layout = Qt.QVBoxLayout(self.top_widget)
        self.top_grid_layout = Qt.QGridLayout()
        self.top_layout.addLayout(self.top_grid_layout)

        self.settings = Qt.QSettings("GNU Radio", "testTagModule")

        try:
            if StrictVersion(Qt.qVersion()) < StrictVersion("5.0.0"):
                self.restoreGeometry(self.settings.value("geometry").toByteArray())
            else:
                self.restoreGeometry(self.settings.value("geometry"))
        except BaseException as exc:
            print(f"Qt GUI: Could not restore geometry: {str(exc)}", file=sys.stderr)

        ##################################################
        # Variables
        ##################################################
        self.burst = burst = False
        self.variable_qtgui_label_0 = variable_qtgui_label_0 = burst
        self.samp_rate = samp_rate = 32000

        ##################################################
        # Blocks
        ##################################################

        self._variable_qtgui_label_0_tool_bar = Qt.QToolBar(self)

        if None:
            self._variable_qtgui_label_0_formatter = None
        else:
            self._variable_qtgui_label_0_formatter = lambda x: str(x)

        self._variable_qtgui_label_0_tool_bar.addWidget(Qt.QLabel("burst"))
        self._variable_qtgui_label_0_label = Qt.QLabel(str(self._variable_qtgui_label_0_formatter(self.variable_qtgui_label_0)))
        self._variable_qtgui_label_0_tool_bar.addWidget(self._variable_qtgui_label_0_label)
        self.top_layout.addWidget(self._variable_qtgui_label_0_tool_bar)
        _burst_check_box = Qt.QCheckBox("'burst'")
        self._burst_choices = {True: True, False: False}
        self._burst_choices_inv = dict((v,k) for k,v in self._burst_choices.items())
        self._burst_callback = lambda i: Qt.QMetaObject.invokeMethod(_burst_check_box, "setChecked", Qt.Q_ARG("bool", self._burst_choices_inv[i]))
        self._burst_callback(self.burst)
        _burst_check_box.stateChanged.connect(lambda i: self.set_burst(self._burst_choices[bool(i)]))
        self.top_layout.addWidget(_burst_check_box)
        self.blocks_tagged_file_sink_0_0_0_0 = blocks.tagged_file_sink(gr.sizeof_gr_complex*1, samp_rate)
        self.blocks_tagged_file_sink_0_0_0 = blocks.tagged_file_sink(gr.sizeof_gr_complex*1, samp_rate)
        self.blocks_tagged_file_sink_0_0 = blocks.tagged_file_sink(gr.sizeof_gr_complex*1, samp_rate)
        self.blocks_tagged_file_sink_0 = blocks.tagged_file_sink(gr.sizeof_gr_complex*1, samp_rate)
        self.analog_fastnoise_source_x_0 = analog.fastnoise_source_c(analog.GR_GAUSSIAN, 1, 0, 8192)
        self.add_tag_module_add_tag_0 = add_tag_module.add_tag(False)
        self.add_tag_module_add_tag_0.set_burst(False)


        ##################################################
        # Connections
        ##################################################
        self.connect((self.add_tag_module_add_tag_0, 0), (self.blocks_tagged_file_sink_0, 0))
        self.connect((self.add_tag_module_add_tag_0, 1), (self.blocks_tagged_file_sink_0_0, 0))
        self.connect((self.add_tag_module_add_tag_0, 2), (self.blocks_tagged_file_sink_0_0_0, 0))
        self.connect((self.add_tag_module_add_tag_0, 3), (self.blocks_tagged_file_sink_0_0_0_0, 0))
        self.connect((self.analog_fastnoise_source_x_0, 0), (self.add_tag_module_add_tag_0, 1))
        self.connect((self.analog_fastnoise_source_x_0, 0), (self.add_tag_module_add_tag_0, 2))
        self.connect((self.analog_fastnoise_source_x_0, 0), (self.add_tag_module_add_tag_0, 3))
        self.connect((self.analog_fastnoise_source_x_0, 0), (self.add_tag_module_add_tag_0, 0))


    def closeEvent(self, event):
        self.settings = Qt.QSettings("GNU Radio", "testTagModule")
        self.settings.setValue("geometry", self.saveGeometry())
        self.stop()
        self.wait()

        event.accept()

    def get_burst(self):
        return self.burst

    def set_burst(self, burst):
        self.burst = burst
        self._burst_callback(self.burst)
        self.set_variable_qtgui_label_0(self.burst)

    def get_variable_qtgui_label_0(self):
        return self.variable_qtgui_label_0

    def set_variable_qtgui_label_0(self, variable_qtgui_label_0):
        self.variable_qtgui_label_0 = variable_qtgui_label_0
        Qt.QMetaObject.invokeMethod(self._variable_qtgui_label_0_label, "setText", Qt.Q_ARG("QString", str(self._variable_qtgui_label_0_formatter(self.variable_qtgui_label_0))))

    def get_samp_rate(self):
        return self.samp_rate

    def set_samp_rate(self, samp_rate):
        self.samp_rate = samp_rate




def main(top_block_cls=testTagModule, options=None):

    if StrictVersion("4.5.0") <= StrictVersion(Qt.qVersion()) < StrictVersion("5.0.0"):
        style = gr.prefs().get_string('qtgui', 'style', 'raster')
        Qt.QApplication.setGraphicsSystem(style)
    qapp = Qt.QApplication(sys.argv)

    tb = top_block_cls()

    tb.start()

    tb.show()

    def sig_handler(sig=None, frame=None):
        tb.stop()
        tb.wait()

        Qt.QApplication.quit()

    signal.signal(signal.SIGINT, sig_handler)
    signal.signal(signal.SIGTERM, sig_handler)

    timer = Qt.QTimer()
    timer.start(500)
    timer.timeout.connect(lambda: None)

    qapp.exec_()

if __name__ == '__main__':
    main()
