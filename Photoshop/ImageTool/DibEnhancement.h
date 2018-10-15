#pragma once

void DibInverse(CDib& dib); //���� ����
void DibBrightness(CDib& dib, int n); // ��� ����
void DibContrast(CDib& dib, int n); // ��Ϻ� ����
void DibGammaCorrection(CDib& dib, float gamma); //���� ����
void DibHistogram(CDib& dib, float histo[256]);
void DibHistEqual(CDib& dib);// ������׷� �յ�ȭ
bool DibAdd(CDib& dib1, CDib& dib2, CDib& dib3);
bool DibSub(CDib& dib1, CDib& dib2, CDib& dib3);
bool DibAve(CDib& dib1, CDib& dib2, CDib& dib3);
bool DibDif(CDib& dib1, CDib& dib2, CDib& dib3);
bool DibAND(CDib& dib1, CDib& dib2, CDib& dib3);
bool DibOR(CDib& dib1, CDib& dib2, CDib& dib3);
void DibBitPlane(CDib& dib1, int bit, CDib& dib2);