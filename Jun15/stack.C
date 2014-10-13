void stack() {

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
  
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(1111);   

  TCanvas *c = new TCanvas("c","c",600,700);
  c->SetLogy();
  c->SetBottomMargin(0.3);

  int binning = 2000;
  int rebinning = 20;
  int lowEnd = 0;

  TFile *file1 = new TFile("/afs/cern.ch/work/c/charaf/public/LooseResults12June2014/NtuplesForZeynepLimits/MCNtupleAll.root","READ");
  TH1F *h1 = new TH1F("h1","h1",binning,lowEnd,binning);
  //h1->Sumw2();
  h1->SetFillColor(33);
  //h1->SetBinErrorOption(TH1::kPoisson);
  T->Draw("mass>>h1","weight","");

  TFile *file2 = new TFile("/afs/cern.ch/work/c/charaf/public/LooseResults12June2014/NtuplesForZeynepLimits/DataNtupleGammaJet.root","READ");
  TH1F *h2 = new TH1F("h2","h2",binning,lowEnd,binning);
  //h2->Sumw2();
  h2->SetFillColor(38);
  //h2->SetBinErrorOption(TH1::kPoisson);
  T->Draw("mass>>h2","weight","goff");

  TFile *file3 = new TFile("/afs/cern.ch/work/c/charaf/public/LooseResults12June2014/NtuplesForZeynepLimits/DataNtupleJetJet.root","READ");
  TH1F *h3 = new TH1F("h3","h3",binning,lowEnd,binning);
  //h3->Sumw2();
  h3->SetFillColor(36);
  //h3->SetBinErrorOption(TH1::kPoisson);
  T->Draw("mass>>h3","weight","goff");

  TFile *file4 = new TFile("/afs/cern.ch/work/c/charaf/public/LooseResults12June2014/NtuplesForZeynepLimits/DataNtuple.root","READ");
  TH1F *h4 = new TH1F("h4","h4",binning,lowEnd,binning);
  h4->Sumw2();
  //h4->SetBinErrorOption(TH1::kPoisson);
  T->Draw("mass>>h4","weight","goff");

  TH1F *h = new TH1F("h","h",binning,lowEnd,binning);
  //h->SetBinErrorOption(TH1::kPoisson);
  h->Sumw2();

  THStack *hs = new THStack("hs"," test");
  h1->Scale(19521);
  h->Add(h1);
  h->Add(h2);
  h->Add(h3);

  h1->Rebin(rebinning);
  h2->Rebin(rebinning);
  h3->Rebin(rebinning);
  h4->Rebin(rebinning);
  h->Rebin(rebinning);

  hs->Add(h3);
  hs->Add(h2);
  hs->Add(h1);
  hs->SetMinimum(0.01);
  hs->SetMaximum(h4->GetMaximum()*10);
  hs->Draw();
  hs->SetTitle("");
  hs->GetYaxis()->SetTitle("Events / 20 GeV");
  //hs->GetYaxis()->SetTitleSize(0.04);
  //hs->GetYaxis()->SetTitleOffset(1.35);

  hs->GetXaxis()->SetTitle(" ");
  hs->GetXaxis()->SetLabelSize(0);
  h4->SetTitle("");
  h4->SetMarkerSize(0.9);
  h4->Draw("sameE1");

  TLegend *legend = new TLegend(.55,.70,.92,.92);
  legend->AddEntry(h1,"Standard Model #gamma #gamma","f");
  legend->AddEntry(h2,"Standard Model #gamma + jet","f");
  legend->AddEntry(h3,"Standard Model jet + jet","f");
  legend->AddEntry(h4,"Data","EP");
  legend->SetShadowColor(0);
  legend->SetFillColor(0);
  legend->SetLineColor(0);
  legend->Draw();


  TLatex *latex2 = new TLatex();
  latex2->SetNDC();
  latex2->SetTextSize(0.035);
  latex2->SetTextAlign(31);
  latex2->DrawLatex(0.87, 0.95, "CMS Preliminary, 19.52 fb^{-1} at #sqrt{s} = 8 TeV");;

  bool pull = false;
  bool ratio = true; 

  TPad *pad = new TPad("pad", "pad", 0.0, 0.0, 1.0, 1.0);
  pad->SetTopMargin(0.7);
  pad->SetFillColor(0);
  pad->SetGridy(1);
  pad->SetFillStyle(0);
  pad->Draw();
  pad->cd(0);
  // pad->SetRightMargin(0.06);

  TH1F *Pull = h4->Clone();
  float totalErr = 0;
  for(int i = 0; i<h->GetNbinsX(); i++){
      h->SetBinError(i,sqrt( (h->GetBinError(i)**2) + ( (h->GetBinContent(i)*0.15)**2) ) );
      //std::cout <<"h->GetBinContent(i): " << h->GetBinContent(i) << " h->GetBinError(i): " << h->GetBinError(i) <<std::endl;
      totalErr += h->GetBinError(i);
  }
  std::cout << "TOTAL ERROR: " << totalErr << std::endl;
  Pull->Add(h,-1);

  // This is the actual pull
  if(pull){   
      for(int i = 0; i<h->GetNbinsX(); i++){
          //std::cout << "(h->GetBinContent(i): " << h->GetBinContent(i) << "  h4->GetBinContent(i): "<< h4->GetBinContent(i) << std::endl;
          if(h->GetBinError(i) > 0 && h4->GetBinContent(i)>0) 
              //Pull->SetBinContent(i,( h4->GetBinContent(i) -  h->GetBinContent(i) ) / h->GetBinError(i) );
              //Pull->SetBinContent(i,( h4->GetBinContent(i) -  h->GetBinContent(i) ) / ( sqrt((h->GetBinContent(i)*0.16 )**2 + (h->GetBinError(i))**2 ) ) );
              Pull->SetBinContent(i,Pull->GetBinContent(i)/Pull->GetBinError(i));
             
          else Pull->SetBinContent(i,0);
          Pull->SetMaximum(3.5);
          Pull->SetMinimum(-3.5);
          Pull->GetYaxis()->SetTitle("#sigma(Data-Bkg)"); 
      }
  }
  
  if(ratio){
      // This is the ratio
      for(int i = 0; i<h->GetNbinsX(); i++){
          // std::cout << "(h->GetBinContent(i): " << h->GetBinContent(i) << "  h4->GetBinContent(i): "<< h4->GetBinContent(i) << std::endl;   
          if(h->GetBinError(i) > 0  && h4->GetBinContent(i)>0) 
              Pull->SetBinContent(i,( h4->GetBinContent(i) - h->GetBinContent(i) ) /h4->GetBinContent(i) );
//              Pull->SetBinContent(i,( h4->GetBinContent(i) - h->GetBinContent(i) ) /h->GetBinContent(i) );
           else Pull->SetBinContent(i,0);
      }
      Pull->SetMaximum(2);
      Pull->SetMinimum(-2);
      Pull->GetYaxis()->SetTitleOffset(1.4);
      Pull->GetYaxis()->SetTitle("(Data-Bkg)/Data");
  }

  Pull->SetMarkerStyle(20);
  Pull->SetFillColor(2);
  Pull->SetLineColor(1);
  Pull->GetXaxis()->SetLabelSize(0.03);
  Pull->GetXaxis()->SetTitleSize(0.04);
  Pull->GetXaxis()->SetTitle("M#gamma#gamma [GeV]");
  Pull->GetYaxis()->SetTitleSize(0.03);
  Pull->GetYaxis()->CenterTitle(true);
  Pull->Draw("HIST");      

  c->SaveAs("stack_mgg_ratio.pdf");
  



}
