//
//  BMPImage.h
//  bitMapFilter
//
//  Created by Trevor Schmidt on 10/7/19.
//  Copyright © 2019 Trevor Schmidt. All rights reserved.
//

#ifndef BMPImage_h
#define BMPImage_h

#include <stdio.h>
#include <stdlib.h>

#include "BMPHeader.h"
#include "DIBHeader.h"
#include "Pixel.h"

typedef struct{
    BMPHeader bmpHeader;
    DIBHeader dibHeader;
    Pixel** pixelArray;
    
    unsigned int numPaddingBytes;
}BMPImage;

void readBMPImageFromFile(FILE* inputFile, BMPImage* theImage);
void writeBMPImageToFile(FILE* outputFile, BMPImage* theImage);

#endif /* BMPImage_h */
