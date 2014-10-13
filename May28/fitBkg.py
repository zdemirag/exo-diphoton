#!/usr/bin/env python

import ROOT, sys, os, string, re
   
from tdrStyle import *
setTDRStyle()

def main():
    
   from optparse import OptionParser
   parser = OptionParser()
   parser.add_option("-f", "--function", dest="f", type="int")
   parser.add_option("-p", "--pull", dest="p", type="int")
   (options, args) = parser.parse_args()

   function = options.f
   pull = options.p

   ROOT.gStyle.SetOptStat(0)
   ROOT.gStyle.SetOptFit(1111)

   #c = ROOT.TCanvas("c","c",600,700)
   #c.SetLogy()
   #c.SetBottomMargin(0.3)

   f = ROOT.TFile("/afs/cern.ch/work/z/zdemirag/work/Diphoton/CMSSW_5_3_2_patch4/src/May28/allBkg.root","READ")
   h = f.Get("h_Diphoton_Minv_FineBinning")

   h.SetTitle("")
   h.GetXaxis().SetTitle("M#gamma#gamma [GeV]")
   h.GetYaxis().SetTitle("Events / 40 GeV")
   h.GetXaxis().SetTitleSize(0)
   h.GetXaxis().SetLabelSize(0)
   h.Rebin(40)
   h.Draw()


   if f==1:
       fdijet1 = ROOT.TF1("fdijet1","[0]*(1-(x/8000))^[1] / (x/8000)^([2]+[3]*log(x/8000))",300,3000)
       fdijet1.SetParameters(1e-5,7.2,5,0.1);
       fdijet1.SetLineWidth(2);
       fdijet1.SetLineColor(2);
       h.Fit(fdijet1,"MR");
       f1 = ROOT.TF1("f1","[0]*(1-(x/8000))^[1] / (x/8000)^([2]+[3]*log(x/8000))",200,4000);
       f1.SetParameters(fdijet1.GetParameter(0), fdijet1.GetParameter(1),fdijet1.GetParameter(2),fdijet1.GetParameter(3),fdijet1.GetParameter(4));
       f1.SetLineColor(4);
       f1.SetLineStyle(8);
       f1.SetLineWidth(2);
       f1.Draw("SAMEN");

  ## TF1 *fbh = new TF1("fbh","[0]*(1+(x/8000))^[1] / (x/8000)^([2]+[3]*log(x/8000))",300,3000);
##   fbh->SetParameters(1e-5,7.2,5,0.1);
##   fbh->SetLineWidth(2);
##   fbh->SetLineColor(2);
##   if(bh){
##     h->Fit(fbh,"MR");
##     TF1 *f1 = new TF1("f1","[0]*(1+(x/8000))^[1] / (x/8000)^([2]+[3]*log(x/8000))",200,4000);
##     f1->SetParameters(fbh->GetParameter(0), fbh->GetParameter(1),fbh->GetParameter(2),fbh->GetParameter(3));
##   }
  
##   TF1 *fzprime = new TF1("fzprime","pow(x,[0])*TMath::Exp([1] + [2]*x + [3]*x*x )",300,3200);
##   fzprime->SetParameters(-4,10,0,0);
##   fzprime->SetLineWidth(2);
##   fzprime->SetLineColor(2);
##   if(zprime){
##     h->Fit(fzprime,"MR");
##     TF1 *f1 = new TF1("f1","pow(x,[0])*TMath::Exp([1] + [2]*x + [3]*x*x )",200,4000);
##     f1->SetParameters(fzprime->GetParameter(0), fzprime->GetParameter(1),fzprime->GetParameter(2),fzprime->GetParameter(3)); 
##   }




   raw_input("Press Enter to continue...")

if __name__ == "__main__":
    main()
