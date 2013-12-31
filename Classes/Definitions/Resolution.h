//
//  Resolution.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/12.
//
//

#ifndef coconut_sample_Resolution_h
#define coconut_sample_Resolution_h

#define CONTENT_SCALE_LARGE					4.0
#define CONTENT_SCALE_NORMAL				2.0
#define CONTENT_SCALE_SMALL					1.0

#define DESIGN_RESOL_HEIGHT_MIN			320
#define DESIGN_RESOL_HEIGHT_MAX			360
#define DESIGN_RESOL_HEIGHT(height)		(fmaxf(DESIGN_RESOL_HEIGHT_MIN, fmaxf(DESIGN_RESOL_HEIGHT_MAX, height)))

#endif
