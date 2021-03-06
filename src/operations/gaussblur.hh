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

#ifndef GAUSS_BLUR_H
#define GAUSS_BLUR_H

#include <string>

#include "../base/processor.hh"

#include "blender.hh"

namespace PF 
{

  class GaussBlurPar: public BlenderPar
  {
    Property<float> radius;
    ProcessorBase* convert_format;

  public:
    GaussBlurPar();

    bool has_intensity() { return false; }

    VipsImage* build(std::vector<VipsImage*>& in, int first, 
		     VipsImage* imap, VipsImage* omap, 
		     unsigned int& level);
  };

  

  template < OP_TEMPLATE_DEF > 
  class GaussBlurProc: public BlenderProc<OP_TEMPLATE_IMP>
  {
  };

  ProcessorBase* new_gaussblur();
}

#endif 


