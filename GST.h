#pragma once
//
//    FILE: GST.h
// VERSION: 0.1.1
// PURPOSE: Arduino library for Gold Standard Test metrics
//     URL: https://github.com/RobTillaart/GST
//          https://en.wikipedia.org/wiki/Sensitivity_and_specificity
//          https://en.wikipedia.org/wiki/Confusion_matrix
//
// formula's based upon Wikipedia.


#define GST_LIB_VERSION           (F("0.1.1"))


class GST
{
public:
  GST() {};

  //  These four values of the matrix need to be set to get started.
  void setTruePositive(float v = 0)   { TP = v; P = TP + FN; };
  void setTrueNegative(float v = 0)   { TN = v; N = TN + FP; };
  void setFalsePositive(float v = 0)  { FP = v; N = TN + FP; };
  void setFalseNegative(float v = 0)  { FN = v; P = TP + FN; };

  //  These are used for updating the test matrix
  void addTruePositive(float v)   { TP += v; P = TP + FN; };
  void addTrueNegative(float v)   { TN += v; N = TN + FP; };
  void addFalsePositive(float v)  { FP += v; N = TN + FP; };
  void addFalseNegative(float v)  { FN += v; P = TP + FN; };


  //  Basic output functions
  float getTruePositive()   { return TP; };
  float getTrueNegative()   { return TN; };
  float getFalsePositive()  { return FP; };
  float getFalseNegative()  { return FN; };

  float getTotal()          { return  P + N; };
  float getActualPositive() { return  P; };
  float getActualNegative() { return  N; };
  float getTestedPositive() { return TP + FP; };
  float getTestedNegative() { return TN + FN; };

  float sensitivity()       { return TPR(); };
  float specificity()       { return TNR(); };


  float truePositiveRate()  { return TPR(); };
  float TPR() { return TP / P; };
  float trueNegativeRate()  { return TNR(); };
  float TNR() { return TN / N; };
  float falseNegativeRate() { return FNR(); };
  float FNR() { return FN / P; };
  float falsePositiveRate() { return FPR(); };
  float FPR() { return FP / N); };


  float positivePredictiveValue() { return PPV(); };
  float PPV() { return TP / (TP + FP); };
  float negativePredictiveValue() { return NPV(); };
  float NPV() { return TN / (TN + FN); };
  float falseDiscoveryRate() { return FDR(); };
  float FDR() { return FP / (FP + TP); };
  float falseOmissionRate() { return FOR(); };
  float FOR() { return FN / (FN + TN); };


  float positiveLikelihoodRatio() { return LRplus(); };
  float LRplus()  { return TPR() / FPR(); };
  float negativeLikelihoodRatio() { return LRminus(); };
  float LRminus() { return FNR() / TNR(); };


  float prevalenceThreshold()  { return sqrt(FPR()) / (sqrt(TPR()) + sqrt(FPR())); };
  float threatScore()  { return TP / (TP + FN + FP); };
  float criticalSuccessIndex() { return threatScore(); };


  float prevalence()       { return P / (P + N); };
  float accuracy()         { return (TP + TN) / (P + N); };
  float balancedAccuracy() { return (TPR() + TNR()) / 2; };
  float F1Score()          { return (2 * TP)/(2 * TP + FP + FN); };


  float MatthewsCorrelationCoefficient() { return MMC(); };
  float phi() { return MCC(); };
  float MCC() { return (TP*TN - FP*FN)/sqrt((TP+FP) * (TP+FN) * (TN+FP) * (TN+FN)); };
  float FowlkesMallowsIndex() { return FM(); };
  float FM() { return sqrt(PPV()*TPR()); };
  float BookmakerInformedness() { return BM(); };
  float BM() { return TPR() + TNR() - 1; };


  float markedness() { return MK(); };
  float deltaP() { return MK(); };
  float MK() { return PPV() + NPV() - 1; };
  float diagnosticOddsRatio() { return DOR(); };
  float DOR() { return LRplus() / LRminus(); };


private:
  float P  = 0;
  float N  = 0;
  float TP = 0;
  float TN = 0;
  float FP = 0;
  float FN = 0;
};


//  for now identical.
class GoldenStandardTest::GST
{
}


// -- END OF FILE --

