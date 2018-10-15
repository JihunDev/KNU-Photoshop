#pragma once

void DibInverse(CDib& dib); //영상 반전
void DibBrightness(CDib& dib, int n); // 밝기 조절
void DibContrast(CDib& dib, int n); // 명암비 조절
void DibGammaCorrection(CDib& dib, float gamma); //감마 보정
void DibHistogram(CDib& dib, float histo[256]);
void DibHistEqual(CDib& dib);// 히스토그램 균등화
bool DibAdd(CDib& dib1, CDib& dib2, CDib& dib3);
bool DibSub(CDib& dib1, CDib& dib2, CDib& dib3);
bool DibAve(CDib& dib1, CDib& dib2, CDib& dib3);
bool DibDif(CDib& dib1, CDib& dib2, CDib& dib3);
bool DibAND(CDib& dib1, CDib& dib2, CDib& dib3);
bool DibOR(CDib& dib1, CDib& dib2, CDib& dib3);
void DibBitPlane(CDib& dib1, int bit, CDib& dib2);