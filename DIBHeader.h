//
//  DIBHeader.h
//  bitMapFilter
//
//  Created by Trevor Schmidt on 10/7/19.
//  Copyright © 2019 Trevor Schmidt. All rights reserved.
//

#ifndef DIBHeader_h
#define DIBHeader_h

#include <stdio.h>

#define DIBHEADER_SIZE 40

typedef struct{
    unsigned int thisHeaderSize; //4
    int widthOfBitmap; //4
    int heightOfBitmap; //4
    unsigned int numOfColorPlanes; //2
    unsigned int numOfBitsPerPixel; //2
    unsigned int compressionMethod; //4
    unsigned int imageSizeInBytes; //4
    int horizontalResolution; //4
    int verticleResolution; //4
    unsigned int numOfColorsInPalette; //4
    unsigned int numOfImportantColors; //4
}DIBHeader;

void readDIBHeaderFromFile(FILE* inputFile, DIBHeader* theHeader);
void writeDIBHeaderToFile(FILE* outputFile, DIBHeader theHeader);

#endif /* DIBHeader_h */
