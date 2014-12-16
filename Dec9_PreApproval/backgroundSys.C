void backgroundSys() {

  TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");

  // For the canvas:
  tdrStyle->SetCanvasBorderMode(0);
  tdrStyle->SetCanvasColor(kWhite);
  tdrStyle->SetCanvasDefH(600); //Height of canvas
  tdrStyle->SetCanvasDefW(600); //Width of canvas
  tdrStyle->SetCanvasDefX(0);   //POsition on screen
  tdrStyle->SetCanvasDefY(0);
  
  // For the Pad:
  tdrStyle->SetPadBorderMode(0);
  tdrStyle->SetPadColor(kWhite);
  tdrStyle->SetPadGridX(false);
  tdrStyle->SetPadGridY(false);
  tdrStyle->SetGridColor(0);
  tdrStyle->SetGridStyle(3);
  tdrStyle->SetGridWidth(1);

  // For the frame:
  tdrStyle->SetFrameBorderMode(0);
  tdrStyle->SetFrameBorderSize(1);
  tdrStyle->SetFrameFillColor(0);
  tdrStyle->SetFrameFillStyle(0);
  tdrStyle->SetFrameLineColor(1);
  tdrStyle->SetFrameLineStyle(1);
  tdrStyle->SetFrameLineWidth(1);

  // For the histo:
  tdrStyle->SetHistLineColor(1);
  tdrStyle->SetHistLineStyle(0);
  tdrStyle->SetHistLineWidth(1);
  tdrStyle->SetEndErrorSize(2);
  tdrStyle->SetErrorX(0.);

  tdrStyle->SetMarkerStyle(20);

  //For the fit/function:
  tdrStyle->SetOptFit(1);
  tdrStyle->SetFitFormat("5.4g");
  tdrStyle->SetFuncColor(2);
  tdrStyle->SetFuncStyle(1);
  tdrStyle->SetFuncWidth(1);

  //For the date:
  tdrStyle->SetOptDate(0);

  // For the statistics box:
  tdrStyle->SetOptFile(0);
  tdrStyle->SetOptStat("emr"); // To display the mean and RMS:   SetOptStat("mr");
  tdrStyle->SetStatColor(kWhite);
  tdrStyle->SetStatFont(42);
  tdrStyle->SetStatFontSize(0.045);
  tdrStyle->SetStatTextColor(1);
  tdrStyle->SetStatFormat("6.4g");
  tdrStyle->SetStatBorderSize(1);
  tdrStyle->SetStatH(0.1);
  tdrStyle->SetStatW(0.19);

  // Margins:
  tdrStyle->SetPadTopMargin(0.07);
  tdrStyle->SetPadBottomMargin(0.13);
  tdrStyle->SetPadLeftMargin(0.13);
  tdrStyle->SetPadRightMargin(0.05);

  // For the Global title:
  //tdrStyle->SetOptTitle(0);
  tdrStyle->SetTitleFont(35);
  tdrStyle->SetTitleColor(1);
  tdrStyle->SetTitleTextColor(1);
  tdrStyle->SetTitleFillColor(10);
  tdrStyle->SetTitleFontSize(0.045);
  tdrStyle->SetTitleX(0.15); // Set the position of the title box
  tdrStyle->SetTitleBorderSize(0);

  // For the axis titles:
  tdrStyle->SetTitleColor(1, "XYZ");
  tdrStyle->SetTitleFont(42, "XYZ");
  tdrStyle->SetTitleSize(0.05, "XYZ");
  tdrStyle->SetTitleXOffset(0.9);
  tdrStyle->SetTitleYOffset(1.05);
  
  // For the axis labels:
  tdrStyle->SetLabelColor(1, "XYZ");
  tdrStyle->SetLabelFont(42, "XYZ");
  tdrStyle->SetLabelOffset(0.007, "XYZ");
  tdrStyle->SetLabelSize(0.03, "XYZ");

  // For the axis:
  tdrStyle->SetAxisColor(1, "XYZ");
  tdrStyle->SetStripDecimals(kTRUE);
  tdrStyle->SetTickLength(0.03, "XYZ");
  tdrStyle->SetNdivisions(510, "XYZ");
  tdrStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  tdrStyle->SetPadTickY(1);

  // Change for log plots:
  tdrStyle->SetOptLogx(0);
  tdrStyle->SetOptLogy(0);
  tdrStyle->SetOptLogz(0);

  // Postscript options:
  tdrStyle->SetPaperSize(20.,20.);
  tdrStyle->SetPalette(1);
  
  const Int_t NRGBs = 5;
  const Int_t NCont = 255;
  
  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
  Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
  Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  tdrStyle->SetNumberContours(NCont);
  
  gROOT -> ForceStyle();

  tdrStyle->cd();

  TString location = "/afs/cern.ch/work/c/charaf/public/ForDiPhoton/ZeynepNtuplesDec14/";
  
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(1111);   

  TCanvas *c = new TCanvas("c","c",600,700);
  c->SetLogy();
  c->SetBottomMargin(0.3);

  int binning = 4000;
  int rebinning = 40;
  int lowbin = 300;
  int highbin = 4300;


  //int binning = 500;
  //int rebinning = 40;
  //int lowbin = 300;
  //int highbin = 530;

    // MCNtuple
  TFile *file1 = new TFile(location+"MCNtuple.root","READ");
  TH1F *h1 = new TH1F("h1","h1",binning,lowbin,highbin);
  h1->Sumw2();
  T->Draw("mass>>h1","weight","");

  //Gamma+Jet
  TFile *file2 = new TFile(location+"DataNtupleGammaJet.root","READ");
  TH1F *h2 = new TH1F("h2","h2",binning,lowbin,highbin);
  h2->Sumw2();
  T->Draw("mass>>h2","weight","goff");

  //Jet Jet
  TFile *file3 = new TFile(location+"DataNtupleFF.root","READ");
  TH1F *h3 = new TH1F("h3","h3",binning,lowbin,highbin);
  h3->Sumw2();
  T->Draw("mass>>h3","weight","goff");

  //Data
  TFile *file4 = new TFile(location+"DataNtuple.root","READ");
  TH1F *h4 = new TH1F("h4","h4",binning,lowbin,highbin);
  h4->Sumw2();
  T->Draw("mass>>h4","weight","goff");

  TH1F *h = new TH1F("h","h",binning,lowbin,highbin);
  h->Sumw2();
 
  h1->Scale(19521);
  h->Add(h1);
  h->Add(h2);
  h->Add(h3);
  h->Draw();
  h->SetTitle("");
  h->GetXaxis()->SetTitle("M#gamma#gamma [GeV]");
  h->GetYaxis()->SetTitle("Events / 40 GeV");
  h->GetXaxis()->SetTitleSize(0);
  h->GetXaxis()->SetLabelSize(0);
  //h->GetYaxis()->CenterTitle(true);
  h->Rebin(rebinning);

  std::cout <<"Total Bkg: " << h->Integral()<<std::endl;
  std::cout <<"All MC: " << h1->Integral()<<std::endl;
  std::cout <<"Gamma Jet: " << h2->Integral()<<std::endl;
  std::cout <<"Jet Jet: " << h3->Integral()<<std::endl;
  std::cout <<"Data: " << h4->Integral()<<std::endl;

  TH1F *Pull = h->Clone();
  Pull->Sumw2();

  TH1F *dummy_sys = new TH1F("dummy_sys","dummy_sys",binning/rebinning,lowbin,highbin);

  TGraphAsymmErrors *RatioSys = new TGraphAsymmErrors(h);

  bool dijet = true;
  bool pull = false;
  bool ratio = true;

  TF1 *fdijet1 = new TF1("fdijet1","[0]*(1-(x/8000))^[1] / (x/8000)^([2]+[3]*log(x/8000))",300,2500);
  fdijet1->SetParameters(1e-5,7.2,5,0.1);
  fdijet1->SetLineWidth(0);
  fdijet1->SetLineColor(4);
  fdijet1->SetLineStyle(8);
  if(dijet){
    h->Fit(fdijet1,"MR");
    TF1 *f1 = new TF1("f1","[0]*(1-(x/8000))^[1] / (x/8000)^([2]+[3]*log(x/8000))",300,5000);
    f1->SetParameters(fdijet1->GetParameter(0), fdijet1->GetParameter(1),fdijet1->GetParameter(2),fdijet1->GetParameter(3),fdijet1->GetParameter(4));
  }

  //TF1 *fbh = new TF1("fbh","[0]*(1+(x/8000))^[1] / (x/8000)^([2]+[3]*log(x/8000))",500,2500);
  //TF1 *fbh = new TF1("fbh","[0]*(1+(x/8000))^[1] / (x/8000)^([2]+[3]*log(x/8000))",300,2500);
  TF1 *fbh = new TF1("fbh","[0]*(1+(x/8000))^[1] / (x/8000)^([2]+[3]*log(x/8000))",300,3000);
  fbh->SetParameters(1e-5,7.2,5,0.1);
  fbh->SetLineWidth(2);
  fbh->SetLineColor(4);
  h->Fit(fbh,"MRN");
  TF1 *f2 = new TF1("f2","[0]*(1+(x/8000))^[1] / (x/8000)^([2]+[3]*log(x/8000))",300,5000);
  f2->SetParameters(fbh->GetParameter(0), fbh->GetParameter(1),fbh->GetParameter(2),fbh->GetParameter(3));


  TF1 *fzprime = new TF1("fzprime","[0]*(1-(x/8000))^[1] / (x/8000)^([2]+[3]*log(x/8000))",300,3500);
  // TF1 *fzprime = new TF1("fzprime","pow(x,[0])*TMath::Exp([1] + [2]*x + [3]*x*x )",300,3000);
  //TF1 *fzprime = new TF1("fzprime","pow(x,[0])*TMath::Exp([1] + [2]*x + [3]*x*x )",300,2500);
  //TF1 *fzprime = new TF1("fzprime","pow(x,[0])*TMath::Exp([1] + [2]*x + [3]*x*x )",500,2500);
  fzprime->SetParameters(-4,10,0,0);
  fzprime->SetLineWidth(2);
  fzprime->SetLineColor(4);
  h->Fit(fzprime,"MRN");
  TF1 *f3 = new TF1("f1","[0]*(1-(x/8000))^[1] / (x/8000)^([2]+[3]*log(x/8000))",300,5000);
  //TF1 *f3 = new TF1("f3","pow(x,[0])*TMath::Exp([1] + [2]*x + [3]*x*x )",300,5000);
  f3->SetParameters(fzprime->GetParameter(0), fzprime->GetParameter(1),fzprime->GetParameter(2),fzprime->GetParameter(3));


  TGraphAsymmErrors *Band= new TGraphAsymmErrors();
  
  for(int hbin = 0; hbin<h->GetNbinsX()+1; hbin++){

      Band->SetPoint(hbin+1,h->GetBinCenter(hbin+1),f1->Eval((h->GetBinCenter(hbin+1))));
      float point = f1->Eval(h->GetBinCenter(hbin+1)); 
      float down = TMath::Abs(point - f3->Eval(h->GetBinCenter(hbin+1))); 
      //float down = TMath::Abs(point - f2->Eval(h->GetBinCenter(hbin+1))); 
      float up = TMath::Abs(point - f2->Eval(h->GetBinCenter(hbin+1)));

      std::cout << "point: " << f1->Eval(h->GetBinCenter(hbin+1)) << " down: " << down/point << " up: " << up/point << std::endl;
      Band->SetPointError(hbin+1,0.,0.,down,up);
      //std::cout << "hbin:" << hbin << std::endl;
  }
  Band->SetFillColor(33);
  Band->SetLineColor(33);
  Band->SetFillStyle(3001);
  Band->SetMarkerSize(0);
  Band->Draw("e3same");
  f2->SetLineColor(33);
  f3->SetLineColor(33);
  f2->Draw("same");
  f3->Draw("same");
  h->Draw("same");

  //gStyle->SetOptFit(kFALSE);

  f1->SetLineColor(4);
  f1->SetLineStyle(8);
  f1->SetLineWidth(2);
  f1->Draw("SAMEN");

  TPad *pad = new TPad("pad", "pad", 0.0, 0.0, 1.0, 1.0);
  pad->SetTopMargin(0.7);
  pad->SetFillColor(0);
  pad->SetGridy(1);
  pad->SetFillStyle(0);
  pad->Draw();
  pad->cd(0);
  // pad->SetRightMargin(0.06);

  //Uncertainty Band! Functions for the MC Background

  TF1 *f_pdf = new TF1("pdf"," exp([0]+[1]*x)",300,5000);
  f_pdf->SetParameters(0.513852,6.03e-4); 

  TF1 *f_kfactor = new TF1("kfactor"," [0]*exp([1]+[2]*x)",300,5000);
  f_kfactor->SetParameters(5.06,-2.459e-2,5.66e-4);

  TH1F *dummy = new TH1F("","",binning,lowbin,highbin);
  
  

  

  //TGraphAsymmErrors *RatioSys = dummy->Clone();


  for (int hbin = 0; hbin<h->GetNbinsX()+1; hbin++){

      float uncert = 0.0;

      //uncert += (f_pdf->Eval(h->GetBinCenter(hbin+1)) / 100. * h->GetBinContent(hbin+1));
      uncert += 5.0**2;
      uncert += (f_pdf->Eval(h->GetBinCenter(hbin+1)))**2;
      uncert += (f_kfactor->Eval(h->GetBinCenter(hbin+1)))**2;

      //std::cout << " Uncert1: " << sqrt(uncert) << std::endl;
      
      uncert = sqrt(uncert) / 100. * h->GetBinContent(hbin+1);

      //std::cout << " K Factor Sys:  " << f_kfactor->Eval(h->GetBinCenter(hbin+1)) << std::endl;
      //std::cout << " PDF Sys:  " << f_pdf->Eval(h->GetBinCenter(hbin+1)) << std::endl;

      if(h->GetBinContent(hbin+1) > 0){
          
          Pull->SetBinContent(hbin+1, ( f1->Eval(h->GetBinCenter(hbin+1))  - h->GetBinContent(hbin+1) )/ h->GetBinContent(hbin+1)  );
          Pull->SetBinError(hbin+1, h->GetBinError(hbin+1)/h->GetBinContent(hbin+1) * Pull->GetBinContent(hbin+1));
          
          float fit = f1->Eval(h->GetBinCenter(hbin+1));
          float bin =  h->GetBinContent(hbin+1);

          float sigma_f_h = 0.;
          float sigma_f_l = 0.;
          //float sigma_f_h = TMath::Abs(f1->Eval(h->GetBinCenter(hbin+1)) - f2->Eval(h->GetBinCenter(hbin+1)));
          //float sigma_f_l = TMath::Abs(f1->Eval(h->GetBinCenter(hbin+1)) - f3->Eval(h->GetBinCenter(hbin+1)));
         
          float sigma_b = uncert ; 
          //float uncertainty = TMath::Sqrt( (fit/bin)**2 * ( sigma_f**2 / fit**2 + sigma_b**2 /bin**2 )   );

          std::cout << "hbin: " << hbin <<" Sigma_B : " << sigma_b/bin << std::endl;
          dummy_sys->SetBinContent(hbin+1,sigma_b/bin*100);

          float uncertainty_l = TMath::Sqrt(  ( sigma_f_l**2 / fit**2 + sigma_b**2 /bin**2 )   );
          float uncertainty_h = TMath::Sqrt(  ( sigma_f_h**2 / fit**2 + sigma_b**2 /bin**2 )   );
          
          //std::cout << "Mass: " <<  h->GetBinCenter(hbin+1) << " fit: " << fit << " bin: " << bin << " sigma_f_h(%): " << sigma_f_h/fit << " sigma_f_l(%): " << sigma_f_l/fit  << " sigma_b (%): " << sigma_b/bin << " uncertainty low: " << uncertainty_l <<  " uncertainty high: " << uncertainty_h  << std::endl; 

          //std::cout << "hbin: " <<h->GetBinLowEdge(hbin+1) << std::endl;
          RatioSys->SetPoint(hbin+1,h->GetBinCenter(hbin+1),0.0);
          RatioSys->SetPointError(hbin+1,0.,0.,uncertainty_l,uncertainty_h);

          //RatioSys->SetBinContent(hbin+1,0);
          //RatioSys->SetBinError(hbin+1, uncertainty);

          ////RatioSys->SetBinError(hbin+1, uncert/h->GetBinContent(hbin+1));

      }
      else{
          Pull->SetBinContent(hbin+1,0);
          Pull->SetBinError(hbin+1, 0);
      }      

  }


  std::cout << RatioSys->GetX() << std::endl;

  TF1 *f_nominal = new TF1("nominal","0",0,5000);

  RatioSys->SetFillColor(33);
  RatioSys->SetLineColor(33);
  
  
  RatioSys->SetMarkerSize(0);

  dummy->SetMaximum(1);
  dummy->SetMinimum(-1);
  dummy->GetYaxis()->SetTitle("(Fit-Bkg)/Bkg");
  dummy->GetXaxis()->SetLabelSize(0.03);
  dummy->GetXaxis()->SetTitleSize(0.04);
  dummy->GetXaxis()->SetTitle("M#gamma#gamma [GeV]");
  dummy->GetYaxis()->SetTitleSize(0.04);
  dummy->GetYaxis()->CenterTitle(true);
  dummy->GetYaxis()->SetNdivisions(5);
  
  dummy->Draw("");
  RatioSys->Draw("samee3");
 
  //RatioSys->GetHistogram()->SetAxisRange(300., 4300.,"X");

  Pull->SetMarkerStyle(4);
  Pull->SetMarkerColor(1);
  Pull->SetLineColor(1);
  Pull->SetMarkerSize(0.5);
  Pull->GetYaxis()->SetNdivisions(5);
  Pull->Draw("epsame");
  //c->SaveAs("bkgFit_ratio_Binning1.pdf");

  f_nominal->SetLineStyle(2);
  f_nominal->SetLineColor(4);
  f_nominal->Draw("same");

  //c->SaveAs("set_sys.pdf");
  //c->SaveAs("set_sys.C");

  TCanvas *c2 = new TCanvas("c2","c2",600,700);
  c2->SetLogy();
  dummy_sys->Draw("");
  
}



