//
//  DIBHeader.c
//  bitMapFilter
//
//  Created by Trevor Schmidt on 10/7/19.
//  Copyright © 2019 Trevor Schmidt. All rights reserved.
//

#include "DIBHeader.h"
#include <stdio.h>


void readDIBHeaderFromFile(FILE* inputFile, DIBHeader* theHeader)
{
    fread(&theHeader->thisHeaderSize, 4, 1, inputFile);
    fread(&theHeader->widthOfBitmap, 4, 1, inputFile);
    fread(&theHeader->heightOfBitmap, 4, 1, inputFile);
    fread(&theHeader->numOfColorPlanes, 2, 1, inputFile);
    fread(&theHeader->numOfBitsPerPixel, 2, 1, inputFile);
    fread(&theHeader->compressionMethod, 4, 1, inputFile);
    fread(&theHeader->imageSizeInBytes, 4, 1, inputFile);
    fread(&theHeader->horizontalResolution, 4, 1, inputFile);
    fread(&theHeader->verticleResolution, 4, 1, inputFile);
    fread(&theHeader->numOfColorsInPalette, 4, 1, inputFile);
    fread(&theHeader->numOfImportantColors, 4, 1, inputFile);
}

void writeDIBHeaderToFile(FILE* outputFile, DIBHeader theHeader)
{
    fwrite(&theHeader.thisHeaderSize, 4, 1, outputFile);
    fwrite(&theHeader.widthOfBitmap, 4, 1, outputFile);
    fwrite(&theHeader.heightOfBitmap, 4, 1, outputFile);
    fwrite(&theHeader.numOfColorPlanes, 2, 1, outputFile);
    fwrite(&theHeader.numOfBitsPerPixel, 2, 1, outputFile);
    fwrite(&theHeader.compressionMethod, 4, 1, outputFile);
    fwrite(&theHeader.imageSizeInBytes, 4, 1, outputFile);
    fwrite(&theHeader.horizontalResolution, 4, 1, outputFile);
    fwrite(&theHeader.verticleResolution, 4, 1, outputFile);
    fwrite(&theHeader.numOfColorsInPalette, 4, 1, outputFile);
    fwrite(&theHeader.numOfImportantColors, 4, 1, outputFile);
}
