//
//  BMPImage.c
//  bitMapFilter
//
//  Created by Trevor Schmidt on 10/7/19.
//  Copyright © 2019 Trevor Schmidt. All rights reserved.
//

#include "BMPImage.h"
#include <stdio.h>


void readBMPImageFromFile(FILE* inputFile, BMPImage* theImage)
{
    
    theImage->pixelArray = malloc(theImage->dibHeader.heightOfBitmap * sizeof(struct pixel*));
    
    for (unsigned int i = 0; i < theImage->dibHeader.heightOfBitmap; ++i)
    {
        theImage->pixelArray[i] = malloc(theImage->dibHeader.widthOfBitmap * sizeof(struct pixel*));
    }
    for (unsigned int i = 0; i < theImage->dibHeader.heightOfBitmap; ++i)
    {
        for (unsigned int j = 0; j < theImage->dibHeader.widthOfBitmap; ++j)
        {
            Pixel pixel;
            readPixelFromFile(inputFile, &pixel);
            theImage->pixelArray[i][j] = pixel;
        }
    }
}

void writeBMPImageToFile(FILE* outputFile, BMPImage* theImage){
    for (unsigned int i = 0; i < theImage->dibHeader.heightOfBitmap; ++i)
    {
        for (unsigned int j = 0; j < theImage->dibHeader.widthOfBitmap; ++j)
        {
            Pixel pixel;
            pixel = theImage->pixelArray[i][j];
            writePixelToFile(outputFile, pixel);
        }
    }
}
