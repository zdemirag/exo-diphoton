#ifndef diphotonreso_h
#define diphotonreso_h
#include<sys/stat.h>
#include<sys/types.h>
 
#include <TROOT.h>
#include <TFile.h>
#include <TChain.h>
#include <TTree.h>
#include <TBranch.h>
#include "TH1.h"
#include "TH2.h"
#include <TMinuit.h>
#include <TRandom.h>
#include <string>
#include <iostream>
#include <fstream>
#include <TMath.h>
#include <stdio.h>
#include <TString.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TH1I.h>
#include <TSystemFile.h>
#include <TSystemDirectory.h>
#include <TDCacheFile.h>
#include <TCanvas.h>
#include <TList.h>
#include <Riostream.h> 
#include <TGraphAsymmErrors.h>
#include <map>
#include "TRFIOFile.h"
#include "TMath.h"
#include <vector>
#include <TList.h>
#include <set>
#include "TPaveStats.h"
#include "TColor.h"
#include "TFractionFitter.h"
#include "TPad.h"
#include "TLegend.h"
#include "TGraphErrors.h"
#include "TLine.h"
#include "TStyle.h" 
#include "TPaveLabel.h" 
#include "TCut.h" 



#include "RooDataHist.h"
#include "RooDataSet.h"
#include "RooHistPdf.h"
#include "RooRealVar.h"

#include "RooArgSet.h"
#include "RooArgList.h"
#include "RooAddPdf.h"
#include "RooAbsReal.h"
#include "RooMinuit.h"
#include "RooChi2Var.h"
#include "RooHist.h"
#include "RooCurve.h"
#include "RooMultiVarGaussian.h"


 
#ifdef __MAKECINT__                           
#pragma link C++ class map<string,TCanvas*>;
#pragma link C++ class map<string,TPad*>;
#pragma link C++ class map<string,TLegend*>;
#pragma link C++ class map<string,TGraphErrors*>;
#pragma link C++ class map<string,TLine*>;
#pragma link C++ class vector<bool>+;
#pragma link C++ class vector<double>+;
#pragma link C++ class map<TString,TH1D*>+;
#endif





using namespace RooFit; 
using namespace std;        
using namespace ROOT;
 
 
class diphotonreso {
 public :
  
  diphotonreso();
  virtual ~diphotonreso();
  virtual void Loop();
  
};
#endif

#ifdef diphotonreso_cxx
diphotonreso::diphotonreso()
{            
}


diphotonreso::~diphotonreso()
{
}
#endif
