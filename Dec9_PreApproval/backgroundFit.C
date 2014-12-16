void backgroundFit() {

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
  //h->Draw();
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
  TH1F *RatioSys = h->Clone();
  
  h->Draw();

  bool dijet = true;
  bool pull = false;
  bool ratio = true;

  TF1 *fdijet1 = new TF1("fdijet1","[0]*(1-(x/8000))^[1] / (x/8000)^([2]+[3]*log(x/8000))",300,2500);
  fdijet1->SetParameters(1e-5,7.2,5,0.1);
  fdijet1->SetLineWidth(2);
  fdijet1->SetLineColor(2);
  if(dijet){
    h->Fit(fdijet1,"MR");
    TF1 *f1 = new TF1("f1","[0]*(1-(x/8000))^[1] / (x/8000)^([2]+[3]*log(x/8000))",300,4000);
    f1->SetParameters(fdijet1->GetParameter(0), fdijet1->GetParameter(1),fdijet1->GetParameter(2),fdijet1->GetParameter(3),fdijet1->GetParameter(4));
  }

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
  f_kfactor->SetParameters(5.06e-02,-2.459e-1,5.66e-4);


  for (int hbin = 0; hbin<h->GetNbinsX()+1; hbin++){
      float uncert = 0.0;
      uncert += (f_pdf->Eval(h->GetBinCenter(hbin+1)) / 100. * h->GetBinContent(hbin+1));

      if(h->GetBinContent(hbin+1) > 0){
          Pull->SetBinContent(hbin+1, ( f1->Eval(h->GetBinCenter(hbin+1))  - h->GetBinContent(hbin+1) )/ h->GetBinContent(hbin+1)  );
          Pull->SetBinError(hbin+1, h->GetBinError(hbin+1)/h->GetBinContent(hbin+1) * Pull->GetBinContent(hbin+1));
          RatioSys->SetBinContent(hbin+1,0);
          RatioSys->SetBinError(hbin+1, uncert/h->GetBinContent(hbin+1));
      }
      else{
          Pull->SetBinContent(hbin+1,0);
          Pull->SetBinError(hbin+1, 0);
      }      
  }

  RatioSys->SetFillColor(33);
  RatioSys->SetLineColor(33);
  Pull->SetMaximum(1.5);
  Pull->SetMinimum(-1.5);
  Pull->GetYaxis()->SetTitle("(Fit-Bkg)/Bkg");
  RatioSys->SetMarkerSize(0);
  Pull->GetXaxis()->SetLabelSize(0.03);
  Pull->GetXaxis()->SetTitleSize(0.04);
  Pull->GetXaxis()->SetTitle("M#gamma#gamma [GeV]");
  Pull->GetYaxis()->SetTitleSize(0.04);
  Pull->GetYaxis()->CenterTitle(true);
  //RatioSys->Draw("e3");

	//  Pull->SetMarkerStyle(20);
 // Pull->SetMarkerColor(1);
 // Pull->SetLineColor(1);
  //Pull->SetMarkerSize(0.8);
  Pull->Draw("HIST");
  //c->SaveAs("bkgFit_ratio_Binning1.pdf");
}






/*
  TCanvas *c2 = new TCanvas("c2","c2",600,700);
  c2->SetLogy();
  c2->SetBottomMargin(0.3);

  h4->Rebin(rebinning);
  h4->SetAxisRange(0,2000);
  h4->SetTitle("Data and Fit Overlayed");
  h4->GetXaxis()->SetTitle("M#gamma#gamma [GeV]");
  h4->GetYaxis()->SetTitle("Events / 40 GeV");
  h4->GetXaxis()->SetTitleSize(0);
  h4->GetXaxis()->SetLabelSize(0);
  h4->Draw("");
  f1->Draw("SAMEN");

  float sum = 0;
  for(int i = 0; i<h4->GetNbinsX(); i++){
      //std::cout <<"i:" << i  <<" h4->GetXaxis()->GetBinCenter(i))+10: " << h4->GetXaxis()->GetBinCenter(i)+10 << " h4->GetBinContent(i): "  << h4->GetBinContent(i) <<std::endl;
      //std::cout <<"i:" << i  <<" f1->Eval(h4->GetBinCenter(i)+25): " << f1->Eval(h4->GetBinCenter(i)+25) << std::endl;
      //if(i>4){
      //sum += f1->Eval(h4->GetBinCenter(i)); 
      //std::cout << "SUM: " << sum << std::endl;
      //}
  }
  //std::cout << "Integral for Data between 300 and 3 TeV: " << h4->Integral(8,75) << std::endl;
  //std::cout << "Integral for MC between 300 and 3 TeV: " << h->Integral(8,75) << std::endl;
  //std::cout << "Integral for Fit between 300 and 3 TeV: " <<  sum << std::endl;

  std::cout << "Integral for Data between 300 and 4 TeV: " << h4->Integral() << std::endl;
  std::cout << "Integral for MC between 300 and 4 TeV: " << h->Integral() << std::endl;
  std::cout << "Integral for Fit between 300 and 4 TeV: " <<  f1->Integral(300,4000)/rebinning << std::endl;

  TLatex *t = new TLatex();
  t->SetNDC();
  t->SetTextAlign(22);
  t->SetTextFont(63);
  t->SetTextSizePixels(20);
  t->DrawLatex(0.65,0.75,"Fit range: 300 GeV - 4 TeV");
  t->DrawLatex(0.65,0.70,"N_{Data} in range: 2450 Events");
  t->DrawLatex(0.65,0.65,"N_{MC} in range: 2549.42 Events ");
  t->DrawLatex(0.65,0.60,"N_{Fit} in range: 2490.39 Events ");

  t->SetTextAlign(13); //align at top left
  t->SetTextAlign(12); // left, vertically centered
  t->SetTextAlign(22); // centered horizontally and vertically
  t->SetTextAlign(11); //default bottom alignment
  
  TPad *pad2 = new TPad("pad2", "pad2", 0.0, 0.0, 1.0, 1.0);
  pad2->SetTopMargin(0.7);
  pad2->SetFillColor(0);
  pad2->SetGridy(1);
  pad2->SetFillStyle(0);
  pad2->Draw();
  pad2->cd(0);

  TH1F *data_RatioSys = h4->Clone();

  // This is the actual pull
  // if(pullFordata) {
    for(int i = 0; i<h4->GetNbinsX(); i++){
      if(h4->GetBinError(i) > 0) data_RatioSys->SetBinContent(i,(h4->GetBinContent(i) - f1->Eval(h4->GetBinCenter(i))) / f1->Eval(h4->GetBinCenter(i)));
      //if(h4->GetBinError(i) > 0) data_RatioSys->SetBinContent(i,(h4->GetBinContent(i) - f1->Eval(h4->GetBinCenter(i))) / h4->GetBinError(i));
      else data_RatioSys->SetBinContent(i,0);
      data_RatioSys->SetMaximum(1.5);
      data_RatioSys->SetMinimum(-1.5);
      data_RatioSys->GetYaxis()->SetTitle("(Data-Fit)/Fit"); 
    }
    // }

  data_RatioSys->SetMarkerStyle(20);
  
  
  data_RatioSys->SetFillColor(2);
  data_RatioSys->SetLineColor(1);
  data_RatioSys->GetXaxis()->SetLabelSize(0.03);
  data_RatioSys->GetXaxis()->SetTitleSize(0.04);
  data_RatioSys->GetXaxis()->SetTitle("M#gamma#gamma [GeV]");
  data_RatioSys->GetYaxis()->SetTitleSize(0.04);
  
  data_RatioSys->GetYaxis()->CenterTitle(true);
  data_RatioSys->Draw("HIST");      
  

  //c2->SaveAs("data_ratio_Binning1.pdf");

*/
