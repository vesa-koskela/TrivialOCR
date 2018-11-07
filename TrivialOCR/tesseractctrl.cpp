#include "tesseractctrl.h"
#include <QDebug>

TesseractCtrl::TesseractCtrl()
{
    char *outText;

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }

    // Open input image with leptonica library
    Pix *image = pixRead("/home/vesa/Projects/trivialocr/TrivialOCR/Images/phototest.tif");
    api->SetImage(image);
    // Get OCR result
    outText = api->GetUTF8Text();
    qDebug() << "OCR output:" << outText;

    // Destroy used object and release memory
    api->End();
    delete [] outText;
    pixDestroy(&image);


}