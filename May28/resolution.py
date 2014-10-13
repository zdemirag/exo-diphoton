#!/usr/bin/env python

import ROOT
from ROOT import RooFit
from ROOT import *



from tdrStyle import *
setTDRStyle()

nmass = 30
 
arr_sigma = [0]
arr_err = [0]

def main():
    
    ROOT.gSystem.Load("libRooFit.so")
    ROOT.gSystem.Load("libRooFitCore.so")

    ROOT.gSystem.SetIncludePath( "-I$ROOFITSYS/include" );
    gROOT.LoadMacro("RooDCBShape.cxx+")

    ROOT.gROOT.SetStyle("Plain")
    
    #ROOT.gROOT.ProcessLineSync(".x RooDoubleSidedCB.cxx+")
    ROOT.gROOT.ProcessLineSync(".x RooDCBShape.cxx+")
    gStyle.SetOptFit(0111)
   
    masses = ["50","55","60","65","70","75","80","85","90","95","100","105","110","120","130","140","150","200","300","500","550","600","650","700","750","800","900","1000","1500","2000","3000"]
    mass= [50,55,60,65,70,75,80,85,90,95,100,105,110,120,130,140,150,200,300,500,550,600,650,700,750,800,900,1000,1500,2000,3000];
    c = {}

    value = [0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.]
    error = [0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.]
        
    
    f = ROOT.TFile("dipho_all.root","READ")
    tree = f.Get("vartree")

    f_new = ROOT.TFile("new.root","RECREATE")
    #gSystem.SetOptStat(1)
    
    for i in range(0,nmass):
        
        c[i] =  TCanvas("Diphoton Mass Resolution for masses "+masses[i]+ "GeV and "+masses[i+1]+ "GeV ","Diphoton Mass Resolution for masses "+masses[i]+ "GeV and "+masses[i+1]+ "GeV ",800,600);

        reso = RooRealVar("reso","reso",-0.15,0.15)
        gen_diphotonmass =  RooRealVar("gen_diphotonmass","gen_diphotonmass",0,4000)
        dh = RooDataSet("dh","dh",RooArgSet(reso,gen_diphotonmass),ROOT.RooFit.Import(tree),ROOT.RooFit.Cut("gen_diphotonmass < "+masses[i+1]+" && gen_diphotonmass >"+masses[i]));

        
        mean = RooRealVar("#Deltam_{Voig}","mean",0,-0.1,0.1) ;
        width = RooRealVar("#Gamma_{Voig}","width",0.1,0,1);
        sigma = RooRealVar("#sigma_{Voig}","sigma",0.1,-1,1) ;

        signal_voig = ROOT.RooVoigtian("voigtian","voigtian", reso, mean, width, sigma, kFALSE);
        signal_gaus = ROOT.RooGaussian("gaussian","gaussian", reso, mean, sigma);
        signal_landau = ROOT.RooLandau("landau","landau",reso,mean,sigma);
        signal_bw = ROOT.RooBreitWigner("bw","bw",reso,mean,sigma)
        
        ## dCBBias   = RooRealVar("#Deltam_{DCB}","Double CB Bias",       1.57817e-04, -0.2, 0.2, "GeV");
##         dCBSigma  = RooRealVar("#sigma_{DCB}", "Double CB Width",      4.35154e-02, 0, 0.2, "GeV")
##         dCBCutL   = RooRealVar("al_{DCB}",     "Double CB Cut left",   4.99903e+00, 0, 10.)
##         dCBCutR   = RooRealVar("ar_{DCB}",     "Double CB Cut right",  9.74488e+00, 0, 10.)
##         dCBPowerL = RooRealVar("nl_{DCB}",     "Double CB Power left", 2.47845e+01, 0, 100.)
##         dCBPowerR = RooRealVar("nr_{DCB}",     "Double CB Power right",1., 0, 100.)
        dCBBias   = RooRealVar("#Deltam_{DCB}","Double CB Bias",       0, -0.05, 0.05)
        dCBSigma  = RooRealVar("#sigma_{DCB}", "Double CB Width",      0.01, 0, 0.05)
        dCBCutL   = RooRealVar("al_{DCB}",     "Double CB Cut left",   1.2, 0.1, 50.)
        dCBCutR   = RooRealVar("ar_{DCB}",     "Double CB Cut right",  6, 0.1, 10.)
        dCBPowerL = RooRealVar("nl_{DCB}",     "Double CB Power left", 0.8, 0.1, 2.)
        dCBPowerR = RooRealVar("nr_{DCB}",     "Double CB Power right",50., 0.2, 50.)
        
        #signal = ROOT.RooDoubleSidedCB("doublesidedCB","Double Sided Crystal Ball PDF",reso,dCBBias, dCBSigma, dCBCutL, dCBCutR, dCBPowerR,  dCBPowerL);
        signal = ROOT.RooDCBShape("dCBall", "A double Crystal Ball lineshape", reso, dCBBias, dCBSigma, dCBCutL, dCBCutR, dCBPowerL, dCBPowerR);


        signal_cb  = ROOT.RooCBShape("cb","cb",reso,dCBBias,dCBSigma,dCBCutL, dCBPowerL)

        #signal = ROOT.RooFFTConvPdf("gcb","landau (X) dscrystalball",reso,signal_landau,signal_dcb);
        #signal = ROOT.RooFFTConvPdf("gcb","landau (X) crystalball",reso,signal_landau,signal_cb);
        #signal = ROOT.RooFFTConvPdf("gcb","gaus (X) dscrystalball",reso,signal_gaus,signal_dcb);
        #signal = ROOT.RooFFTConvPdf("gcb","gaus (X) crystalball",reso,signal_gaus,signal_cb);

        #signal = ROOT.RooFFTConvPdf("gcb","bw (X) crystalball",reso,signal_bw,signal_cb);
        #signal = ROOT.RooFFTConvPdf("gcb","bw (X) dscrystalball",reso,signal_bw,signal_dcb);
        #signal = ROOT.RooFFTConvPdf("gcb","bw (X) gaus",reso,signal_bw,signal_gaus)

        # Works!
        #signal = ROOT.RooFFTConvPdf("gcb","voig (X) crystalball",reso,signal_voig,signal_cb);
        #signal = ROOT.RooFFTConvPdf("gcb","voig (X) dcrystalball",reso,signal_voig,signal_dcb);
        
        #signal = ROOT.RooDoubleSidedCB("doublesidedCB","Double Sided Crystal Ball PDF",reso,dCBBias, dCBSigma, dCBCutL, dCBPowerL, dCBCutR,dCBPowerR);

        dterr = RooRealVar("dterr","per-event error on dt",0.01,10)

        print reso.getError()
        
        #Build a gaussian resolution model scaled by the per-event error = gauss(dt,bias,sigma*dterr)
        #bias2=  RooRealVar("bias2","bias2",0,-10,10) ;
        #sigma2=RooRealVar("sigma2","per-event error scale factor",1,0.1,10) ;
        #gm=RooGaussModel("gm1","gauss model scaled bt per-event error",reso,bias2,sigma2,dterr)

        #pdfDtErr = RooLandau("pdfDtErr","pdfDtErr",dterr,ROOT.RooFit.RooConst(1),ROOT.RooFit.RooConst(0.25)) ;
        #dh = RooDataSet("dh","dh",RooArgSet(reso,gen_diphotonmass),ROOT.RooFit.Import(tree),ROOT.RooFit.Cut("gen_diphotonmass < "+masses[i+1]+" && gen_diphotonmass >"+masses[i]));


        
        
        xframe = reso.frame()#.Title("Diphoton Mass Resolution for masses "+masses[i]+ "GeV and "+masses[i+1]+ "GeV")) ;
        signal.fitTo(dh)
        dh.plotOn(xframe)#,ROOT.RooFit.DataError(RooAbsData.SumW2))

        
        signal.plotOn(xframe)



   
        argset_fit = ROOT.RooArgSet(dCBBias, dCBSigma, dCBCutL, dCBPowerL, dCBCutR,dCBPowerR,mean,sigma,width)
        signal.paramOn(xframe,RooFit.Parameters(argset_fit),RooFit.Format("NE",RooFit.AutoPrecision(1)),RooFit.Layout(0.57,0.90,0.90))

        dh.statOn(xframe,RooFit.Format("NE",RooFit.AutoPrecision(1)),RooFit.Layout(0.1,0.45,0.90)) ;

        chi2_text = TPaveText(0.1273408,0.5485893,0.3277154,0.6489028,"BRNDC")#0.2,0.8,0.4,0.9,"BRNDC")#0.13, 0.435, "Test")#Form("#chi^{2} fit = %s" %round(xframe.chiSquare(7),2)))
        chi2_text.AddText("#chi^{2} fit = %s" %round(xframe.chiSquare(6),2))
        chi2_text.SetTextSize(0.04)
        chi2_text.SetTextColor(2)
        chi2_text.SetShadowColor(0)
        chi2_text.SetFillColor(0)
        chi2_text.SetLineColor(0)
        xframe.addObject(chi2_text)
        
        xframe.GetYaxis().SetTitleOffset(1.20) ;
        xframe.GetXaxis().SetTitle("m_{Reco} - m_{Gen} / m_{Gen}")
                
        xframe.SetTitle("Diphoton Mass Resolution for M_{Gen} ["+masses[i]+ " , "+masses[i+1]+ "] GeV");
        xframe.Draw()

        xframe.Write("")

        
        print "********************"
        print "Chi2:",xframe.chiSquare(6)

        print dCBSigma.getVal(),"+-", dCBSigma.getError()
        value[i] = dCBSigma.getVal()
        error[i] = dCBSigma.getError()

        print "value"
        for j in range(0,i):
            print value[j]

        print "error"
        for k in range(0,i):
            print error[k]

        c[i].SaveAs("Resolution_plots/gen_diphotonmass"+masses[i]+ "_"+masses[i+1]+".pdf")
        raw_input("Press Enter to continue...")
    f_new.Close()

if __name__ == "__main__":
    main()
