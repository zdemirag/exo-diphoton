// ---------------------------------------------------------
// This macro fits a voigtian to the inv diphoton resolution
// gets the sigma of that fit and plots it as a function
// of diphoton mass. 
// ---------------------------------------------------------




//
#include "diphotonreso.h"
#include "RooFit.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"
#include "TFile.h"
#include "RooVoigtian.h"
#include "RooLandau.h"
#include "RooCBShape.h"
#include "RooDCBShape.h"
//#include "RooDoubleSidedCB.h"



#ifndef __CINT__
#include "RooGlobalFunc.h"
#include "RooDCBShape.h"
#endif

void diphotonreso::Loop(){

const int nmass = 2;
const TString masses[]={"0","100","200"};
double mass[] = {0,100,200};
int rebin[]= {2, 2, 2};
double fitsigma[nmass];
double fitsigmaError[nmass];
double xe[] ={0.,0.,0.};
double value[nmass];

double integral[nmass];

 

  //gSystem->SetIncludePath("-I$ROOFITSYS/include/")
  //gROOT->ProcessLineSync(".x RooDoubleSidedCB.cxx+") ;

  TFile *f = new TFile("dipho_all.root","READ");
  TCanvas* c[nmass];

  for(int i=0; i<nmass; i++){
    c[i] =  new TCanvas("Diphoton Mass Resolution for masses "+masses[i]+ "GeV and "+masses[i+1]+ "GeV ","Diphoton Mass Resolution for masses "+masses[i]+ "GeV and "+masses[i+1]+ "GeV ",800,800);
    
    TTree* tree = (TTree*)f->Get("vartree");
    RooRealVar reso("reso","reso",-0.2,0.2) ;
    RooRealVar gen_diphotonmass("gen_diphotonmass","gen_diphotonmass",0,4000);
    RooDataSet dh("dh","dh",RooArgSet(reso,gen_diphotonmass),RooFit::Import(*tree),RooFit::Cut("gen_diphotonmass < "+masses[i+1]+" && gen_diphotonmass >"+masses[i]));

    // Construct voigtian
    RooRealVar mean("mean","mean",0,-0.1,0.1) ;
    RooRealVar width("width","width",0.1,0,1);
    RooRealVar sigma("sigma","sigma",0.1,-1,1) ;

    //RooVoigtian signal_voig("voigtian","voigtian", reso, mean, width, sigma, kFALSE);
    //RooGaussian signal_gaus("gaussian","gaussian", reso, mean, sigma);
    //RooLandau signal_landau("landau","landau",reso,mean,sigma);
    
    RooRealVar meancb("meancb","meancb",0,-0.2,0.2);
    RooRealVar sigmacb("sigmacb","sigmacb",0.1,-1,1);
    RooRealVar a("a","a",1,0.1,10);
    RooRealVar n("n","n",5,0.1,10);
    //RooCBShape signal_cb("cb","cb",reso,meancb,sigmacb,a,n);

    //RooFFTConvPdf signal("gcb","landau (X) crystalball",reso,signal_landau,signal_cb);


    RooRealVar dCBBias ("#Deltam_{DCB}", "Double CB Bias", -.2, -20, 20, "GeV");
    RooRealVar dCBSigma ("#sigma_{DCB}", "Double CB Width", 2., 0.02, 20., "GeV");
    RooRealVar dCBCutL ("al_{DCB}", "Double CB Cut left", 1., 0.1, 50.);
    RooRealVar dCBCutR ("ar_{DCB}", "Double CB Cut right", 1., 0.1, 50.);
    RooRealVar dCBPowerL ("nl_{DCB}", "Double CB Power left", 2., 0.2, 50.);
    RooRealVar dCBPowerR ("nr_{DCB}", "Double CB Power right", 2., 0.2, 50.);
    float cutoff_cb = 1.0;
    dCBCutL.setVal(cutoff_cb);
    dCBCutR.setVal(cutoff_cb);

#ifdef __CINT__
    gROOT->ProcessLineSync(".x RooDCBShape.cxx+") ;
#endif  

    //RooDoubleSidedCB signal("dCBall", "A double Crystal Ball lineshape", mass, dCBBias, dCBSigma, dCBCutL, dCBPowerL, dCBCutR, dCBPowerR);
    
    RooDCBShape signal("dCBall", "A double Crystal Ball lineshape", reso, dCBBias, dCBSigma, dCBCutL, dCBCutR, dCBPowerL, dCBPowerR);

    RooPlot* xframe = reso.frame(Title("Diphoton Mass Resolution for masses "+masses[i]+ "GeV and "+masses[i+1]+ "GeV")) ;
    RooFitResult* r1 = signal.fitTo(dh,Save()) ;
    //r1->Print();
    dh.plotOn(xframe);
    signal.plotOn(xframe);
    fitsigma[i] = TMath::Abs(sigma.getVal());
    fitsigmaError[i] = TMath::Abs(sigma.getError());

    reso.setRange("sig",0.5,1) ;
    RooAbsReal* ig = signal.createIntegral(reso,NormSet(reso),Range("sig"));
    //integral[i] = ig.getVal();

    xframe->GetYaxis()->SetTitleOffset(1.5) ; 
    xframe->SetTitle("");
    xframe->Draw();

    //pt = new TPaveText(0.12,0.7,0.37,0.77, "NDC"); // NDC sets coords
    // relative to pad dimensions
    //pt->SetFillColor(0); // text is black on white
    //pt->SetTextSize(0.02); 
    //pt->SetTextAlign(12);
    //pt->AddText(masses[i]+ "GeV and "+masses[i+1]+ "GeV");
    //pt->Draw("same");
  }

}
