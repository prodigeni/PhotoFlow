/* 
 */

/*

    Copyright (C) 2014 Ferrero Andrea

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.


 */

/*

    These files are distributed with PhotoFlow - http://aferrero2707.github.io/PhotoFlow/

 */

#ifndef DRAW_CONFIG_DIALOG_HH
#define DRAW_CONFIG_DIALOG_HH

#include <gtkmm.h>

#include "../operation_config_dialog.hh"


namespace PF {

  class DrawConfigDialog: public OperationConfigDialog
{
  //#ifdef GTKMM_2
  Gtk::VBox controlsBox;
  Gtk::HBox colorButtonsBox1;
  Gtk::HBox colorButtonsBox2;
  Gtk::HBox penBox;

  Gtk::Label pen_color_label, bgd_color_label;

  Gtk::ColorButton pen_color_button, bgd_color_button;

  //Gtk::Label lbrightness, lcontrast;
  //Gtk::Alignment lcontrastAl, lbrightnessAl;

  //Gtk::Adjustment contrastAdj, brightnessAdj;
  //Gtk::HScale contrastScale, brightnessScale;
  //#endif

  Slider pen_size;
  Slider pen_opacity;

public:
  DrawConfigDialog( Layer* l );

  void open();

  unsigned int get_pen_size() { return 100; };
  float get_pen_opacity() { return 0.5; }

  void on_pen_color_changed();
  void on_bgd_color_changed();

  void start_stroke();
  void draw_point( double x, double y );

  void pointer_press_event( int button, double x, double y, int mod_key );
  void pointer_release_event( int button, double x, double y, int mod_key );
  void pointer_motion_event( int button, double x, double y, int mod_key );
};

}

#endif
