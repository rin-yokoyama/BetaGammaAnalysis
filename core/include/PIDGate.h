/**
 * @file PIDGate.h
 * @author Rin Yokoyama (yokoyama@cns.s.u-tokyo.ac.jp)
 * @brief PID gate from a TCutG or an ellipse
 * @version 0.1
 * @date 2023-01-19
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __PID_GATE_H__
#define __PID_GATE_H__

#include <iostream>
#include <fstream>
#include <vector>
#include "TCutG.h"
#include "TList.h"
#include "TFile.h"
#include "TKey.h"
#include "TObjArray.h"

class PIDGate
{
public:
    /// @brief This function generates a vector of PIDGate objects from file.
    /// if the file name ends with ".root", it opens the file as a ROOT file
    /// and load TCutG objects in the file. Otherwise, it assumes that the file
    /// is a text file of a list of ellipse parameters
    /// @param icutname input file name
    /// @param outputList pointer to the output list when used in an TSelector object
    /// @return vector of PIDGate object loaded from the input file
    static const std::vector<PIDGate> LoadCut(std::string icutname, TList *outputList = nullptr);

    PIDGate() {}
    PIDGate(TCutG *aCut, TList *outputList = nullptr);
    PIDGate(std::string isoname, Double_t a, Double_t b, Double_t x0, Double_t y0, TList *outputList = nullptr);
    virtual ~PIDGate();
    void initializeCut(TCutG *aCut);
    virtual void initializeHistos(TList *outputList);
    bool IsInside(Double_t x, Double_t y) const;

protected:
    /// double numberOfImplants
    int32_t numberOfImplants;
    /// double numberOfImplants
    int32_t numberOfPID;
    /// number of correlated implants in an event
    int32_t numberOfCorrelatedImp;
    /// myCutG: cut for PID
    TCutG *myCutG;
    Double_t ellipseA;
    Double_t ellipseB;
    Double_t ellipseX0;
    Double_t ellipseY0;

    TObjArray *fHistArray;
    std::string isotopeName;
};

#endif // __PID_GATE_H__
