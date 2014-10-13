#!/usr/bin/env python

import ROOT
from ROOT import RooFit

from tdrStyle import *
setTDRStyle()

def main():

   from optparse import OptionParser
   parser = OptionParser()
   parser.add_option("-m", "--mass", dest="m", type="int", default=1000)
   parser.add_option("-c", "--coupling", dest="c", type="string", default="001")
   (options, args) = parser.parse_args()

   mass = options.m
   coupling = options.c
   
   ROOT.gSystem.Load("libRooFit.so")
   ROOT.gSystem.Load("libRooFitCore.so")
   ROOT.gROOT.SetStyle("Plain")

   ROOT.gROOT.ProcessLineSync(".x RooDoubleSidedCB.cxx+")

   mass_min = mass - 500
   mass_max = mass + 500
   c = ROOT.TCanvas("c","c",600,500)
   c.SetLogy()

    ############### GEN LEVEL ################

   fileLocation = "/afs/cern.ch/work/s/scooper/public/DiPhotonTrees/"
   f = ROOT.TFile("%s/diphoton_tree_RSGravToGG_kMpl-%s_M-%s_TuneZ2star_8TeV-pythia_merged.root" % (fileLocation,coupling,mass),"READ")  
   t_gen = f.Get("diphotonSignalMCAnalyzer/fTree")
   histo_gen = ROOT.TH1F("histo_gen","M_{#gamma #gamma} Gen for M =%s GeV" % (mass),10000,mass-500,mass+500)
   t_gen.Draw("DiphotonGen.Minv>>histo_gen")
   
   raw_input("Just drew you the gen level distribution, Press enter and click on the Canvas to Continue")

   minv_gen = ROOT.RooRealVar("minv_gen","M_{#gamma #gamma} Gen for M=%s GeV with c = %s" % (mass,coupling) ,mass_min,mass_max,"GeV")
   data_gen = ROOT.RooDataHist("data_gen","data_signal_gen",ROOT.RooArgList(minv_gen),histo_gen)

   bwMean_gen = ROOT.RooRealVar("bwMean_gen","bwMean_gen",mass,mass-100, mass+100)
   bwSigma_gen = ROOT.RooRealVar("bwSigma_gen","bwSigma_gen",mass/100,0,mass/50)
   bwshape_gen = ROOT.RooBreitWigner("bwshape_gen","bwshape_gen",minv_gen,bwMean_gen,bwSigma_gen)

   mframe_gen = minv_gen.frame()
   data_gen.plotOn(mframe_gen,RooFit.Name(data_gen.GetName()))
   bwshape_gen.fitTo(data_gen)
   bwshape_gen.plotOn(mframe_gen,RooFit.Name(bwshape_gen.GetName()))

   argset_model_gen = ROOT.RooArgSet(bwMean_gen,bwSigma_gen)
   bwshape_gen.paramOn(mframe_gen,RooFit.Parameters(argset_model_gen), RooFit.Format("NE"), RooFit.Layout(0.47,0.89,0.89))
   mframe_gen.Print("v")
   mframe_gen.Draw()

   raw_input("Just drew you the gen level fit, Press enter and click on the Canvas to Continue")

   ############### RECO LEVEL ################

   fileLocation2 = "/afs/cern.ch/user/s/scooper/work/public/4Zeynep/"
   f2  = ROOT.TFile("%s/histograms_diphoton_tree_RSGravToGG_kMpl-%s_M-%s_TuneZ2star_8TeV-pythia_merged.root" % (fileLocation2,coupling,mass), "READ")
   histo = f2.Get("h_Diphoton_Minv_FineBinning")
   histoOrig = histo.Clone()
   histo.Rebin(5)

   minv = ROOT.RooRealVar("minv","M_{#gamma #gamma}",mass_min,mass_max,"GeV")
   data = ROOT.RooDataHist("data","data_signal",ROOT.RooArgList(minv),histo)

   mframe = minv.frame()

   # Construct CB
   mean_CB  = ROOT.RooRealVar("meanCB","mean of gaussian",0,-mass-500,mass+500.) 
   sigma_CB = ROOT.RooRealVar("sigmaCB","width of gaussian",mass/100,0,mass)

   #mean_CB  = ROOT.RooRealVar("meanCB","mean of gaussian",0,9.53029e+02) 
   #sigma_CB = ROOT.RooRealVar("sigmaCB","width of gaussian",4.74992e+00) 

   if(mass == 1500 or  mass == 1000):
      alpha_CB = ROOT.RooRealVar("alphaCB","gaussian tail",1.5,-5,5)
      #alpha_CB = ROOT.RooRealVar("alphaCB","gaussian tail",2.04103e-01)
      n_var = ROOT.RooRealVar("n_varCB","normalization",2.4,0.1,10.0)
      #n_var = ROOT.RooRealVar("n_varCB","normalization",5.30176e+00)
      
      alpha_CB_2 = ROOT.RooRealVar("alphaCB_2","gaussian tail 2",1.5,-10,10)
      #alpha_CB_2 = ROOT.RooRealVar("alphaCB_2","gaussian tail 2",6.11090e-01)
      n_var_2 = ROOT.RooRealVar("n_varCB_2","normalization 2",0,-15,15.0)
      #n_var_2 = ROOT.RooRealVar("n_varCB_2","normalization 2",0,-15,15.0)
   if(mass == 2000 or mass == 1250 or mass == 1750):

      alpha_CB = ROOT.RooRealVar("alphaCB","gaussian tail",0,-1.5,1.5)
      n_var = ROOT.RooRealVar("n_varCB","normalization",2.4,.0,15.0)

      alpha_CB_2 = ROOT.RooRealVar("alphaCB_2","gaussian tail 2",0,-1.5,1.5)
      n_var_2 = ROOT.RooRealVar("n_varCB_2","normalization 2",0,-15,15.0)

   if(mass == 3000 or mass == 2500):
      alpha_CB = ROOT.RooRealVar("alphaCB","gaussian tail",1.5,0,10.0)
      n_var = ROOT.RooRealVar("n_varCB","normalization",2,.0,10.0)

      alpha_CB_2 = ROOT.RooRealVar("alphaCB_2","gaussian tail 2",0,-1.5,1.5)
      n_var_2 = ROOT.RooRealVar("n_varCB_2","normalization 2",0,-15,15.0)

   # FIXING BW !!
   bwMean = ROOT.RooRealVar("bwMean","bwMean",bwMean_gen.getValV())
   bwSigma = ROOT.RooRealVar("bwSigma","bwSigma", bwSigma_gen.getValV())

   crystalball = ROOT.RooCBShape("crystalball","Crystal Ball PDF",minv,mean_CB,sigma_CB,alpha_CB,n_var)
   bwshape = ROOT.RooBreitWigner("bwshape","bwshape",minv,bwMean,bwSigma)

   doublesidedCB = ROOT.RooDoubleSidedCB("doublesidedCB","Double Sided Crystal Ball PDF",minv,mean_CB,sigma_CB,alpha_CB,n_var,alpha_CB_2,n_var_2)

   data.plotOn(mframe,RooFit.Name(data.GetName()))
   #doublesidedCB.fitTo(data)
   #doublesidedCB.plotOn(mframe,RooFit.Name(doublesidedCB.GetName()))

   #myFit = ROOT.RooFFTConvPdf("myFit","bw x crystalball",minv,bwshape,crystalball)
   myFit = ROOT.RooFFTConvPdf("myFit","bw x crystalball",minv,bwshape,doublesidedCB)

   #argset_cb = ROOT.RooArgSet(crystalball)
   argset_cb = ROOT.RooArgSet(doublesidedCB)
   argset_bw = ROOT.RooArgSet(bwshape)

   data.plotOn(mframe,RooFit.Name(data.GetName()))

   #myFit.fitTo(data,RooFit.Extended())
   myFit.fitTo(data)
   myFit.plotOn(mframe,RooFit.Name(myFit.GetName()))
   mframe.chiSquare(myFit.GetName(),data.GetName())

   chi2 =  mframe.chiSquare(myFit.GetName(),data.GetName())
   print "*** CHI2: ******:  ", chi2
   
   argset_myFit = ROOT.RooArgSet(mean_CB,sigma_CB,alpha_CB,n_var,alpha_CB_2,n_var_2,bwMean,bwSigma)
   myFit.paramOn(mframe,RooFit.Parameters(argset_myFit), RooFit.Format("NE"), RooFit.Layout(0.47,0.89,0.89))

   mframe.Print("v")
   mframe.Draw()
##    paramList = myFit.getParameters(data)
##    paramList.Print("v")

   raw_input("Press Enter to continue...")

if __name__ == "__main__":
    main()



    ### ADDITIONAL STUFF

   #myFit.plotOn(mframe,RooFit.Components(argset_cb),RooFit.LineStyle(2),RooFit.LineColor(2)) ;
   #myFit.plotOn(mframe,RooFit.Components(argset_bw),RooFit.LineStyle(2),RooFit.LineColor(8)) ;

   #bwfrac = ROOT.RooRealVar("bwfrac","fraction of background",0.8,0.,1.) ;
   #cbfrac = ROOT.RooRealVar("cbfrac","fraction of background",0.2,0.,1.) ; 
   #model = ROOT.RooAddPdf("model","g1+a",ROOT.RooArgList(crystalball,bwshape),ROOT.RooArgList(cbfrac,bwfrac))
   #model.fitTo(data)
   #model.plotOn(mframe,RooFit.Name(model.GetName()))
