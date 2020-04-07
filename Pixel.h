//
//  Pixel.h
//  bitMapFilter
//
//  Created by Trevor Schmidt on 10/7/19.
//  Copyright © 2019 Trevor Schmidt. All rights reserved.
//

#ifndef Pixel_h
#define Pixel_h

#include <stdio.h>

#define BYTES_PER_PIXEL 3

typedef struct{
    unsigned char R;
    unsigned char G;
    unsigned char B;
}Pixel;

void readPixelFromFile(FILE* inputFile, Pixel* thePixel);
void writePixelToFile(FILE* outputFile, Pixel thePixel);

#endif /* Pixel_h */
