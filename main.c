//
//  main.c
//  bitMapFilter
//
//  Created by Trevor Schmidt on 10/6/19.
//  Copyright © 2019 Trevor Schmidt. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "BMPHeader.h"
#include "DIBHeader.h"
#include "Pixel.h"
#include "BMPImage.h"

int main(int argc, const char * argv[])
{
    FILE *fp;
    fp = fopen("face.bmp", "rb");
    
    if (argc > 3)
    {
        printf("Failed\n");
        return 1;
    }
    
    FILE *fp2;
    fp2 = fopen("filtered.bmp", "wb");
    
    BMPHeader bmpHeader;
    readBMPHeaderFromFile(fp, &bmpHeader);
    writeBMPHeaderToFile(fp2, bmpHeader);
    
    DIBHeader dibHeader;
    readDIBHeaderFromFile(fp, &dibHeader);
    writeDIBHeaderToFile(fp2, dibHeader);
    
    BMPImage bmpImage;
    readBMPImageFromFile(fp, &bmpImage);
    
    if (argv[2][0] == 'T')
    {
        for (unsigned int i = 0; i < bmpImage.dibHeader.heightOfBitmap; ++i)
        {
            for (unsigned int j = 0; j < bmpImage.dibHeader.widthOfBitmap; ++j)
            {
                if (((bmpImage.pixelArray[i][j].B + bmpImage.pixelArray[i][j].G +   bmpImage.pixelArray[i][j].R) / 3) < 128)
                {
                    bmpImage.pixelArray[i][j].B = 0;
                    bmpImage.pixelArray[i][j].G = 0;
                    bmpImage.pixelArray[i][j].R = 0;
                }
                else
                {
                    bmpImage.pixelArray[i][j].B = 255;
                    bmpImage.pixelArray[i][j].B = 255;
                    bmpImage.pixelArray[i][j].B = 255;
                }
            }
        }
    }
    
    else if (argv[2][0] == 'G')
    {
        for (unsigned int i = 0; i < bmpImage.dibHeader.heightOfBitmap; ++i)
        {
            for (unsigned int j = 0; j < bmpImage.dibHeader.widthOfBitmap; ++j)
            {
                bmpImage.pixelArray[i][j].B = ((bmpImage.pixelArray[i][j].B + bmpImage.pixelArray[i][j].G + bmpImage.pixelArray[i][j].R) / 3);
                bmpImage.pixelArray[i][j].G = bmpImage.pixelArray[i][j].B;
                bmpImage.pixelArray[i][j].R = bmpImage.pixelArray[i][j].B;
            }
        }
    }
    
    else if (argv[2][0] == 'S')
    {
        
        
        
        for (unsigned int i = 0; i < bmpImage.dibHeader.heightOfBitmap; i += 2)
        {
            for (unsigned int j = 0; j < bmpImage.dibHeader.widthOfBitmap; j += 2)
            {
                
            }
        }
    }
    
    if (argv[2][0] != 'S')
    {
        writeBMPImageToFile(fp2, &bmpImage);
    }
    

    fclose(fp);
    fclose(fp2);
    
    return 0;
}
