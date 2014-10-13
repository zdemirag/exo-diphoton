#!/usr/bin/env python

import ROOT
from ROOT import RooFit
from ROOT import *

#from tdrStyle import *
#setTDRStyle()

def main():
    ROOT.gSystem.Load("libRooFit.so")
    ROOT.gSystem.Load("libRooFitCore.so")
    ROOT.gROOT.SetStyle("Plain")
    ROOT.gSystem.SetIncludePath( "-I$ROOFITSYS/include/" )
    ROOT.gROOT.ProcessLineSync(".x RooDoubleSidedCB.cxx+")

    nmass = 2
    masses = ["0","100","200"];

    mass= [0,100,200];
    
    c = []
    
    f = ROOT.TFile("dipho_all.root","READ")
    tree = f.Get("vartree")

    
    for i in nmass:
        
        c[i] =  TCanvas("Diphoton Mass Resolution for masses "+masses[i]+ "GeV and "+masses[i+1]+ "GeV ","Diphoton Mass Resolution for masses "+masses[i]+ "GeV and "+masses[i+1]+ "GeV ",800,800);

        reso = RooRealVar("reso","reso",-0.2,0.2)
        gen_diphotonmass =  RooRealVar("gen_diphotonmass","gen_diphotonmass",0,4000)
        dh = RooDataSet("dh","dh",RooArgSet(reso,gen_diphotonmass),Import(*tree),Cut("gen_diphotonmass < "+masses[i+1]+" && gen_diphotonmass >"+masses[i]));

        dCBBias = RooRealVar("#Deltam_{DCB}", "Double CB Bias", -.2, -20, 20, "GeV");
        dCBSigma= RooRealVar("#sigma_{DCB}", "Double CB Width", 2., 0.02, 20., "GeV")
        dCBCutL = RooRealVar("al_{DCB}", "Double CB Cut left", 1., 0.1, 50.)
        dCBCutR=RooRealVar("ar_{DCB}", "Double CB Cut right", 1., 0.1, 50.)
        dCBPowerL= RooRealVar("nl_{DCB}", "Double CB Power left", 2., 0.2, 50.)
        dCBPowerR =RooRealVar("nr_{DCB}", "Double CB Power right", 2., 0.2, 50.)

        signal = ROOT.RooDoubleSidedCB("doublesidedCB","Double Sided Crystal Ball PDF",reso,dCBBias, dCBSigma, dCBCutL, dCBPowerL, dCBCutR,dCBPowerR);

        xframe = reso.frame(Title("Diphoton Mass Resolution for masses "+masses[i]+ "GeV and "+masses[i+1]+ "GeV")) ;
        signal.fitTo(dh,Save()) ;
        dh.plotOn(xframe);
        signal.plotOn(xframe);
        
        #xframe->GetYaxis()->SetTitleOffset(1.5) ; 
        #xframe->SetTitle("");
        xframe.Draw();

    raw_input("Press Enter to continue...")

if __name__ == "__main__":
    main()

