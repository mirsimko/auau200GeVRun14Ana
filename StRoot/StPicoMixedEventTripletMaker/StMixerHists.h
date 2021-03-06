#ifndef StMixerHists__h
#define StMixerHists__h

/* **************************************************
 *
 * Histogram manager
 *
 * **************************************************
 *
 *  Initial Authors:  
 *            Michael Lomnitz (mrlomnitz@lbl.gov)
 *            Mustafa Mustafa (mmustafa@lbl.gov)
 *  Other authors:
 *         ** Miroslav Simko  (msimko@bnl.gov)
 *
 *  ** Code Maintainer
 *
 * **************************************************
 */

#include "StarClassLibrary/StThreeVectorF.hh"
#include "TH2F.h"

#include "StMixerTriplet.h"

#include <iostream>
using namespace std;

class StMixerHists
{
 public:
  StMixerHists(char* fileBaseName);
  ~StMixerHists();

  void fillSameEvt(const StThreeVectorF& vtx, float weight);
  void fillMixedEvt(const StThreeVectorF& vtx, float weight);
  void fillSameEvtTriplet(StMixerTriplet const* const, int charge, float weight);
  void fillMixedEvtTriplet(StMixerTriplet const* const, int charge, float weight);
  void closeFile();
 private:
  TH2F* mSE_Vtx;
  TH2F* mME_Vtx;
  TH2F* mSE_LS;
  TH2F* mSE_US_plus;
  TH2F* mSE_US_minus;
  TH2F* mME_LS;
  TH2F* mME_US_plus;
  TH2F* mME_US_minus;
};
inline void StMixerHists::fillSameEvt(const StThreeVectorF& vtx, float weight)
{
  mSE_Vtx->Fill(vtx.x(), vtx.y(), weight);
}
inline void StMixerHists::fillMixedEvt(const StThreeVectorF& vtx, float weight)
{
  mME_Vtx->Fill(vtx.x(), vtx.y(), weight);
}
inline void StMixerHists::fillSameEvtTriplet(StMixerTriplet const* const triplet, int charge, float weight)
{
  if(charge == 3) // binary b011 for LC+ or b100 for LC-
  {
    mSE_US_plus-> Fill(triplet->pt(),triplet->m(), weight);
  }
  else if (charge == 4)
  {
    mSE_US_minus-> Fill(triplet->pt(),triplet->m(), weight);
  }
  else
  {
    mSE_LS-> Fill(triplet->pt(),triplet->m(), weight);
  }
  // cout << "SE triplet" << endl;
}
inline void StMixerHists::fillMixedEvtTriplet(StMixerTriplet const* const triplet, int charge, float weight)
{
  if(charge == 3) // binary b011 for LC+ or b100 for LC-
    mME_US_plus-> Fill(triplet->pt(),triplet->m(), weight);
  else if(charge == 4)
    mME_US_minus-> Fill(triplet->pt(),triplet->m(), weight);
  else
    mME_LS-> Fill(triplet->pt(),triplet->m(), weight);
  // cout << "ME triplet" << endl;
}
#endif
