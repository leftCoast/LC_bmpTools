#ifndef bmpFlasher_h
#define bmpFlasher_h


// bmpFlasher contains base classes for a that bmpFlasher holds
// and swaps two .bmp files.


#include <flasher.h>
#include <bmpObj.h>

// *****************************************************
//                     bmpFlasher
// *****************************************************

// bmpFlasher swaps between two bitmaps instead of a colored rectangle.

class bmpFlasher :  public flasher {
    
	public:
				bmpFlasher(int inX,int inY, int width,int height,const char* onBmpPath,const char* offBmpPath);
				bmpFlasher(rect* inRect,const char* onBmp,const char* offBmp);
	virtual	~bmpFlasher(void);

				void	setup(const char* onBmpPath,const char* offBmpPath);
	virtual	void	drawSelf(void);

				bool		mReady;
            bmpObj*	mOnBmp;
            bmpObj*	mOffBmp;     
};

#endif
