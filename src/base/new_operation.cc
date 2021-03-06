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


#include "new_operation.hh"
#include "layer.hh"
#include "../operations/operations.hh"
#include "../operations/vips_operation.hh"

PF::ProcessorBase* PF::new_operation( std::string op_type, PF::Layer* current_layer )
{
  PF::ProcessorBase* processor = NULL;

  if( op_type == "imageread" ) { 

    //processor = new PF::Processor<PF::ImageReaderPar,PF::ImageReader>();
    processor = new_image_reader();

  } else if( op_type == "buffer" ) {

    //processor = new PF::Processor<PF::BlenderPar,PF::BlenderProc>();
    processor = new_buffer();

  } else if( op_type == "blender" ) {

    //processor = new PF::Processor<PF::BlenderPar,PF::BlenderProc>();
    processor = new_blender();

  } else if( op_type == "clone" ) {

    //processor = new PF::Processor<PF::ClonePar,PF::CloneProc>();
    processor = new_clone();

  } else if( op_type == "invert" ) {

    //processor = new PF::Processor<PF::InvertPar,PF::Invert>();
    processor = new_invert();

  } else if( op_type == "uniform" ) {

    //processor = new PF::Processor<PF::InvertPar,PF::Invert>();
    processor = new_uniform();

  } else if( op_type == "gradient" ) {

    //processor = new PF::Processor<PF::GradientPar,PF::Gradient>();
    processor = new_gradient();

  } else if( op_type == "brightness_contrast" ) {

    //processor = new PF::Processor<PF::BrightnessContrastPar,PF::BrightnessContrast>();
    processor = new_brightness_contrast();

  } else if( op_type == "curves" ) {
      
    //processor = new PF::Processor<PF::CurvesPar,PF::Curves>();
    processor = new_curves();

  } else if( op_type == "gaussblur" ) {
      
    //processor = new PF::Processor<PF::CurvesPar,PF::Curves>();
    processor = new_gaussblur();

  } else if( op_type == "convert2lab" ) {

    //processor = new PF::Processor<PF::Convert2LabPar,PF::Convert2LabProc>();
    processor = new_convert2lab();

  } else if( op_type == "draw" ) {

    //processor = new PF::Processor<PF::Convert2LabPar,PF::Convert2LabProc>();
    processor = new_draw();

  } else { // it must be a VIPS operation...

    int pos = op_type.find( "vips-" );
    if( pos != 0 ) return NULL;
    std::string vips_op_type;
    vips_op_type.append(op_type.begin()+5,op_type.end());

    PF::Processor<PF::VipsOperationPar,PF::VipsOperationProc>* vips_op = 
      new PF::Processor<PF::VipsOperationPar,PF::VipsOperationProc>();
    //ProcessorBase* vips_op = new_vips_operation();
    vips_op->get_par()->set_op( vips_op_type.c_str() );
    processor = vips_op;
  }

  if( processor && current_layer )
    current_layer->set_processor( processor );

  return processor;
}
