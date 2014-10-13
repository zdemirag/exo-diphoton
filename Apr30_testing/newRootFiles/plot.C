void plot() {

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



  /*
   graph = new TGraph(9);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineColor(2);
   graph->SetLineStyle(2);
   graph->SetLineWidth(2);
   graph->SetMarkerColor(2);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(0.8);
   graph->SetPoint(0,750,0.2377990484);
   graph->SetPoint(1,1000,0.2913043499);
   graph->SetPoint(2,1250,0.3370562494);
   graph->SetPoint(3,1500,0.3762954175);
   graph->SetPoint(4,1750,0.4098855555);
   graph->SetPoint(5,2000,0.440413475);
   graph->SetPoint(6,2250,0.4653176963);
   graph->SetPoint(7,2500,0.4685668647);
   graph->SetPoint(8,3000,0.4833472967);
  */

  

  /*
  //Acceptance * Efficiency:
  const Int_t n = 9;
  Float_t mass[n]    = {750,1000,1250,1500,1750,2000,2250,2500,3000};
  Float_t AccxEff[n] = {0.2377990484,0.2913043499,0.3370562494,0.3762954175,0.4098855555,0.440413475,0.4653176963,0.4685668647,0.4833472967 }
 // Float_t AccxEff[n] = {0.331938,0.379936,0.420901,0.460234,0.500914,0.528017,0.576227};
 // Float_t ey[n]      = {0.00297353,0.00306546,0.00311809,0.00314066,0.0031517,0.00315378,0.00312095 };

  Float_t ex[n]      = {0,0,0,0,0,0,0,0,0};

  Float_t ey[n]      = {0,0,0,0,0,0,0,0,0};
  Float_t ex[n]      = {0,0,0,0,0,0,0,0,0};


 for(int i = 0; i<n; i++){

   ey[i] = TMath::Sqrt(AccxEff[i]*(1-AccxEff[i])/2500);
   std::cout <<ey[i] <<std::endl;
 }

  */


  /*
  TString c = "005";
  //Signal Width - BW sigma
  if( c == "001" ){
    const Int_t n = 5;
    Float_t mass[n]    = {1000,1500,2000,2500,3000};
    Float_t width[n]   = {0.1676,0.2243,0.2918,0.3594,0.4267};
    Float_t ey[n]      = {0.0013,0.0019,0.0026,0.0032,0.0038};
    Float_t ex[n]      = {0,0,0,0,0};
    
    Float_t width_cb[n] = {6.22,8.54,12.73,16.90,21.69};
    Float_t ey_cb[n]    = {0.24,0.32,0.31,0.38,0.50};
  }
  if( c == "005") {
    const Int_t n = 4;
    Float_t mass[n]    = {1500,2000,2500,3000};
    Float_t width[n]   = {5.323,7.211,8.808,10.688};
    Float_t ey[n]      = {0.048,0.065,0.079,0.096};
    Float_t ex[n]      = {0,0,0,0};
    
    Float_t width_cb[n] = {16.60,16.59,19.16,23.11};
    Float_t ey_cb[n]    = {0.27,0.38,0.43,0.62};
  }
  if(c == "01"){
    const Int_t n = 4;
    Float_t mass[n]    = {1500,2000,2500,3000};
    Float_t width[n]   = {21.47,28.21,35.48,42.53};
    Float_t ey[n]      = {0.19,0.26,0.32,0.39};
    Float_t ex[n]      = {0,0,0,0};
    
    Float_t width_cb[n] = {13.47,17.03,22.58,24.3};
    Float_t ey_cb[n]    = {0.55,0.75,0.85,1.1};
  }


  TCanvas *c1 = new TCanvas("c1","c1",680,600);
  c1->cd();
  c1->SetGridx();

  c1->SetGridy();

  TCanvas *c1 = new TCanvas("c1","c1",680,600);
  c1->cd();
  c1->SetGridx();
  c1->SetGridy();
  
  
  TGraphErrors *gr = new TGraphErrors(n,mass,width_cb,ex,ey_cb);
  //TGraphErrors *gr = new TGraphErrors(n,mass,width,ex,ey);
  gr->SetTitle("RS Graviton Signal for c ="+c);
  gr->GetXaxis()->SetTitle("M#gamma#gamma [GeV]");
  //gr->GetYaxis()->SetTitle("Acceptance * Efficiency");
  gr->GetYaxis()->SetTitle("Signal Width (CB) GeV" );
  gr->SetMarkerColor(4);
  gr->SetMarkerStyle(20);
  gr->SetMarkerSize(1.2);
  gr->Draw("AP");
  */



  
  
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(1111);   

  TCanvas *c = new TCanvas("c","c",600,700);
  c->SetLogy();
  c->SetBottomMargin(0.3);

  int binning = 5000;
  int rebinning = 20;

  TFile *file1 = new TFile("MCNtupleAll.root","READ");
  TH1F *h1 = new TH1F("h1","h1",binning,0,binning);
  h1->Sumw2();
  T->Draw("mass>>h1","weight","");

  TFile *file2 = new TFile("DataNtupleGammaJet.root","READ");
  TH1F *h2 = new TH1F("h2","h2",binning,0,binning);
  h2->Sumw2();
  T->Draw("mass>>h2","weight","goff");

  TFile *file3 = new TFile("DataNtupleJetJet.root","READ");
  TH1F *h3 = new TH1F("h3","h3",binning,0,binning);
  h3->Sumw2();
  T->Draw("mass>>h3","weight","goff");

  TFile *file4 = new TFile("DataNtuple.root","READ");
  TH1F *h4 = new TH1F("h4","h4",binning,0,binning);
  h4->Sumw2();
  T->Draw("mass>>h4","weight","goff");

  TH1F *h = new TH1F("h","h",binning,0,binning);
  h->Sumw2();
 
  h1->Scale(19376);
  h->Add(h1);
  h->Add(h2);
  h->Add(h3);
  h->Draw();
  h->SetTitle("");
  h->GetXaxis()->SetTitle("M#gamma#gamma [GeV]");
  h->GetYaxis()->SetTitle("Events / 20 GeV");
  h->GetXaxis()->SetTitleSize(0);
  h->GetXaxis()->SetLabelSize(0);
  //h->GetYaxis()->CenterTitle(true);
  h->Rebin(rebinning);

  std::cout <<"Total Bkg: " << h->Integral()<<std::endl;
  std::cout <<"All MC: " << h1->Integral()<<std::endl;
  std::cout <<"Gamma Jet :" << h2->Integral()<<std::endl;
  std::cout <<"Jet Jet" << h3->Integral()<<std::endl;
  std::cout <<"Data" << h4->Integral()<<std::endl;
  
  h->Draw();


  bool dijet = true;
  bool bh = false;
  bool zprime = false;

  bool pull = false;
  bool ratio = true;

  TF1 *fdijet1 = new TF1("fdijet1","[0]*(1-(x/8000))^[1] / (x/8000)^([2]+[3]*log(x/8000))",300,2500);
  fdijet1->SetParameters(1e-5,7.2,5,0.1);
  fdijet1->SetLineWidth(2);
  fdijet1->SetLineColor(2);
  if(dijet){
    h->Fit(fdijet1,"MR");
    TF1 *f1 = new TF1("f1","[0]*(1-(x/8000))^[1] / (x/8000)^([2]+[3]*log(x/8000))",200,4000);
    f1->SetParameters(fdijet1->GetParameter(0), fdijet1->GetParameter(1),fdijet1->GetParameter(2),fdijet1->GetParameter(3),fdijet1->GetParameter(4));
  }

  TF1 *fbh = new TF1("fbh","[0]*(1+(x/8000))^[1] / (x/8000)^([2]+[3]*log(x/8000))",200,3000);
  fbh->SetParameters(1e-5,7.2,5,0.1);
  fbh->SetLineWidth(2);
  fbh->SetLineColor(2);
  if(bh){
    h->Fit(fbh,"MR");
    TF1 *f1 = new TF1("f1","[0]*(1+(x/8000))^[1] / (x/8000)^([2]+[3]*log(x/8000))",200,4000);
    f1->SetParameters(fbh->GetParameter(0), fbh->GetParameter(1),fbh->GetParameter(2),fbh->GetParameter(3));
  }
  
  TF1 *fzprime = new TF1("fzprime","pow(x,[0])*TMath::Exp([1] + [2]*x + [3]*x*x )",200,3000);
  fzprime->SetParameters(-4,10,0,0);
  fzprime->SetLineWidth(2);
  fzprime->SetLineColor(2);
  if(zprime){
    h->Fit(fzprime,"MR");
    TF1 *f1 = new TF1("f1","pow(x,[0])*TMath::Exp([1] + [2]*x + [3]*x*x )",200,4000);
    f1->SetParameters(fzprime->GetParameter(0), fzprime->GetParameter(1),fzprime->GetParameter(2),fzprime->GetParameter(3)); 
  }

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

  TH1F *Pull = h->Clone();

  // This is the actual pull
  if(pull){   
    for(int i = 0; i<h->GetNbinsX(); i++){
      if(h->GetBinError(i) > 0  && h->GetBinCenter(i)>290) Pull->SetBinContent(i,(h->GetBinContent(i) - f1->Eval(h->GetBinCenter(i))) / h->GetBinError(i));
      else Pull->SetBinContent(i,0);
      Pull->SetMaximum(3.5);
      Pull->SetMinimum(-3.5);
      Pull->GetYaxis()->SetTitle("#sigma(MC-Fit)"); 
    }
  }

  if(ratio){
  
    // This is the ratio
    for(int i = 0; i<h->GetNbinsX(); i++){
        if(h->GetBinError(i) > 0 && h->GetBinCenter(i)>290.) Pull->SetBinContent(i,(h->GetBinContent(i) - f1->Eval(h->GetBinCenter(i))) / f1->Eval(h->GetBinCenter(i)));
      else Pull->SetBinContent(i,0);
    }
    Pull->SetMaximum(1.5);
    Pull->SetMinimum(-1.5);
    Pull->GetYaxis()->SetTitle("(MC-fit)/fit");
  }

  Pull->SetMarkerStyle(20);
  
  
  Pull->SetFillColor(2);
  Pull->SetLineColor(1);
  Pull->GetXaxis()->SetLabelSize(0.03);
  Pull->GetXaxis()->SetTitleSize(0.04);
  Pull->GetXaxis()->SetTitle("M#gamma#gamma [GeV]");
  Pull->GetYaxis()->SetTitleSize(0.04);
  
  Pull->GetYaxis()->CenterTitle(true);
  Pull->Draw("HIST");      

  //c->SaveAs("bkgFitPlots/bkgFit80_ratio.pdf");
  


  TCanvas *c2 = new TCanvas("c2","c2",600,700);
  c2->SetLogy();
  c2->SetBottomMargin(0.3);

  h4->Rebin(rebinning);
  h4->SetAxisRange(0,2000);
  h4->SetTitle("Data and Fit Overlayed");
  h4->GetXaxis()->SetTitle("M#gamma#gamma [GeV]");
  h4->GetYaxis()->SetTitle("Events / 20 GeV");
  h4->GetXaxis()->SetTitleSize(0);
  h4->GetXaxis()->SetLabelSize(0);
  h4->Draw("");
  f1->Draw("SAMEN");

  float sum = 0;
  for(int i = 0; i<h4->GetNbinsX(); i++){
      std::cout <<"i:" << i  <<" h4->GetXaxis()->GetBinCenter(i))+10: " << h4->GetXaxis()->GetBinCenter(i)+10 << " h4->GetBinContent(i): "  << h4->GetBinContent(i) <<std::endl;
      //std::cout <<"i:" << i  <<" f1->Eval(h4->GetBinCenter(i)+25): " << f1->Eval(h4->GetBinCenter(i)+25) << std::endl;
      //if(i>4){
      //sum += f1->Eval(h4->GetBinCenter(i)); 
      //std::cout << "SUM: " << sum << std::endl;
      //}
  }
  //std::cout << "Integral for Data between 300 and 3 TeV: " << h4->Integral(8,75) << std::endl;
  //std::cout << "Integral for MC between 300 and 3 TeV: " << h->Integral(8,75) << std::endl;
  //std::cout << "Integral for Fit between 300 and 3 TeV: " <<  sum << std::endl;

  std::cout << "Integral for Data between 300 and 4 TeV: " << h4->Integral(16,249) << std::endl;
  std::cout << "Integral for MC between 300 and 4 TeV: " << h->Integral(16,249) << std::endl;
  std::cout << "Integral for Fit between 300 and 4 TeV: " <<  f1->Eval(1000) << " " << f1->Integral(300,4000)/rebinning << std::endl;


  TLatex *t = new TLatex();
  t->SetNDC();
  t->SetTextAlign(22);
  t->SetTextFont(63);
  t->SetTextSizePixels(20);
  t->DrawLatex(0.65,0.75,"Fit range: 300 GeV - 4 TeV");
  t->DrawLatex(0.65,0.70,"N_{Data} in range: 2420 Events");
  t->DrawLatex(0.65,0.65,"N_{MC} in range: 2167.06 Events ");
  // t->DrawLatex(0.65,0.60,"N_{Fit} in range: 7006.3 Events ");
  t->DrawLatex(0.65,0.60,"N_{Fit} in range: 2161.91 Events ");


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

  TH1F *data_Pull = h4->Clone();

  // This is the actual pull
  // if(pullFordata) {
    for(int i = 0; i<h4->GetNbinsX(); i++){
      if(h4->GetBinError(i) > 0) data_Pull->SetBinContent(i,(h4->GetBinContent(i) - f1->Eval(h4->GetBinCenter(i))) / f1->Eval(h4->GetBinCenter(i)));
      //if(h4->GetBinError(i) > 0) data_Pull->SetBinContent(i,(h4->GetBinContent(i) - f1->Eval(h4->GetBinCenter(i))) / h4->GetBinError(i));
      else data_Pull->SetBinContent(i,0);
      data_Pull->SetMaximum(1.5);
      data_Pull->SetMinimum(-1.5);
      data_Pull->GetYaxis()->SetTitle("(Data-Fit)/Fit"); 
    }
    // }

  data_Pull->SetMarkerStyle(20);
  
  
  data_Pull->SetFillColor(2);
  data_Pull->SetLineColor(1);
  data_Pull->GetXaxis()->SetLabelSize(0.03);
  data_Pull->GetXaxis()->SetTitleSize(0.04);
  data_Pull->GetXaxis()->SetTitle("M#gamma#gamma [GeV]");
  data_Pull->GetYaxis()->SetTitleSize(0.04);
  
  data_Pull->GetYaxis()->CenterTitle(true);
  data_Pull->Draw("HIST");      


}
