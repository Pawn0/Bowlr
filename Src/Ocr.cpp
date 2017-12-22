/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "../OculusHeaders/Ocr.h"

//accepts the file name
//loads it into the program
Oculus::Ocr::Ocr(const std::string& fn):fileName(fn){}

std::string Oculus::Ocr::getText(){
    //file processing to get the content should happen here
    img = pixRead(fileName.c_str());
    api->SetImage(img);
    
    content = api->GetUTF8Text();
    return content;
}

Oculus::Ocr::~Ocr(){
    //we destroy the pointers here or we risk a memory leak
    api->End();//end the tesseract engine
    pixDestroy(&img);//delete the picture pointer by ref
    delete [] content;//delete the char array
}

Oculus::Ocr& Oculus::Ocr::operator =(const Ocr& cpy){}

Oculus::Ocr::Ocr(const Ocr& cpy): 
api(new tesseract::TessBaseAPI(*cpy.api)) ,img(new PIX(*cpy.img)){}