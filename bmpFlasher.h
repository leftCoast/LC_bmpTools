#ifndef bmpFlasher_h
#define bmpFlasher_h


#include <flasher.h>
#include <bmpObj.h>


// This extends the original flasher class from swapping between two colors, to swapping
// between two .bmp images. See the flasher class for more public methods to use for this.


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
