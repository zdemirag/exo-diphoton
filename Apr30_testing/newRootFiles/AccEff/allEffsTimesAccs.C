{
//=========Macro generated from canvas: c1_n5/c1_n5
//=========  (Thu Dec 19 14:52:54 2013) by ROOT version5.32/00
   TCanvas *c1_n5 = new TCanvas("c1_n5", "c1_n5",0,0,700,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   c1_n5->SetHighLightColor(2);
   c1_n5->Range(229.7297,0.1025974,3945.946,0.751948);
   c1_n5->SetFillColor(0);
   c1_n5->SetBorderMode(0);
   c1_n5->SetBorderSize(2);
   c1_n5->SetTickx(1);
   c1_n5->SetTicky(1);
   c1_n5->SetLeftMargin(0.14);
   c1_n5->SetRightMargin(0.12);
   c1_n5->SetTopMargin(0.08);
   c1_n5->SetBottomMargin(0.15);
   c1_n5->SetFrameFillStyle(0);
   c1_n5->SetFrameLineWidth(2);
   c1_n5->SetFrameBorderMode(0);
   c1_n5->SetFrameFillStyle(0);
   c1_n5->SetFrameLineWidth(2);
   c1_n5->SetFrameBorderMode(0);
   
   TH1F *test = new TH1F("test","",10,750,3500);
   test->SetMinimum(0.2);
   test->SetMaximum(0.7);
   test->SetStats(0);
   test->SetLineWidth(2);
   test->SetMarkerStyle(8);
   test->SetMarkerSize(0.8);
   test->GetXaxis()->SetTitle("M_{1} [GeV]");
   test->GetXaxis()->SetNdivisions(506);
   test->GetXaxis()->SetLabelFont(42);
   test->GetXaxis()->SetTitleOffset(1.2);
   test->GetXaxis()->SetTitleFont(42);
   test->GetYaxis()->SetTitle("efficiency*acceptance");
   test->GetYaxis()->SetNdivisions(506);
   test->GetYaxis()->SetLabelFont(42);
   test->GetYaxis()->SetTitleOffset(1.2);
   test->GetYaxis()->SetTitleFont(42);
   test->GetZaxis()->SetLabelFont(42);
   test->GetZaxis()->SetTitleSize(0.06);
   test->GetZaxis()->SetTitleOffset(1.1);
   test->GetZaxis()->SetTitleFont(42);
   test->Draw("");
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle("");
   
   TGraph *graph = new TGraph(9);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineColor(2);
   graph->SetLineStyle(3);
   graph->SetLineWidth(2);
   graph->SetMarkerColor(2);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(0.8);
   graph->SetPoint(0,750,0.4125598073);
   graph->SetPoint(1,1000,0.466852814);
   graph->SetPoint(2,1250,0.5118468404);
   graph->SetPoint(3,1500,0.5472701788);
   graph->SetPoint(4,1750,0.589081347);
   graph->SetPoint(5,2000,0.6204102635);
   graph->SetPoint(6,2250,0.6408445239);
   graph->SetPoint(7,2500,0.6485947967);
   graph->SetPoint(8,3000,0.6592876315);
   
   TH1F *Graph_Graph13 = new TH1F("Graph_Graph13","Graph",100,525,3225);
   Graph_Graph13->SetMinimum(0.387887);
   Graph_Graph13->SetMaximum(0.6839604);
   Graph_Graph13->SetDirectory(0);
   Graph_Graph13->SetStats(0);
   Graph_Graph13->SetLineWidth(2);
   Graph_Graph13->SetMarkerStyle(8);
   Graph_Graph13->SetMarkerSize(0.8);
   Graph_Graph13->GetXaxis()->SetNdivisions(506);
   Graph_Graph13->GetXaxis()->SetLabelFont(42);
   Graph_Graph13->GetXaxis()->SetLabelSize(0.073);
   Graph_Graph13->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph13->GetXaxis()->SetTitleFont(42);
   Graph_Graph13->GetYaxis()->SetNdivisions(506);
   Graph_Graph13->GetYaxis()->SetLabelFont(42);
   Graph_Graph13->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph13->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph13->GetYaxis()->SetTitleFont(42);
   Graph_Graph13->GetZaxis()->SetLabelFont(42);
   Graph_Graph13->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph13->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph13->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph13);
   
   multigraph->Add(graph,"l");
   
   graph = new TGraph(8);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineColor(4);
   graph->SetLineStyle(3);
   graph->SetLineWidth(2);
   graph->SetMarkerColor(4);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(0.8);
   graph->SetPoint(0,1250,0.5180621743);
   graph->SetPoint(1,1500,0.5583555698);
   graph->SetPoint(2,1750,0.5870065093);
   graph->SetPoint(3,2000,0.6187176704);
   graph->SetPoint(4,2250,0.6374980211);
   graph->SetPoint(5,2500,0.6507538557);
   graph->SetPoint(6,2750,0.6522362232);
   graph->SetPoint(7,3000,0.6567901373);
   
   TH1F *Graph_Graph14 = new TH1F("Graph_Graph14","Graph",100,1075,3175);
   Graph_Graph14->SetMinimum(0.5041894);
   Graph_Graph14->SetMaximum(0.6706629);
   Graph_Graph14->SetDirectory(0);
   Graph_Graph14->SetStats(0);
   Graph_Graph14->SetLineWidth(2);
   Graph_Graph14->SetMarkerStyle(8);
   Graph_Graph14->SetMarkerSize(0.8);
   Graph_Graph14->GetXaxis()->SetNdivisions(506);
   Graph_Graph14->GetXaxis()->SetLabelFont(42);
   Graph_Graph14->GetXaxis()->SetLabelSize(0.073);
   Graph_Graph14->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph14->GetXaxis()->SetTitleFont(42);
   Graph_Graph14->GetYaxis()->SetNdivisions(506);
   Graph_Graph14->GetYaxis()->SetLabelFont(42);
   Graph_Graph14->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph14->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph14->GetYaxis()->SetTitleFont(42);
   Graph_Graph14->GetZaxis()->SetLabelFont(42);
   Graph_Graph14->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph14->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph14->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph14);
   
   multigraph->Add(graph,"l");
   
   graph = new TGraph(9);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineColor(8);
   graph->SetLineStyle(3);
   graph->SetLineWidth(2);
   graph->SetMarkerColor(8);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(0.8);
   graph->SetPoint(0,1500,0.5540476441);
   graph->SetPoint(1,1750,0.5870676637);
   graph->SetPoint(2,2000,0.6193774343);
   graph->SetPoint(3,2250,0.6345886588);
   graph->SetPoint(4,2500,0.6513373256);
   graph->SetPoint(5,2750,0.6538922191);
   graph->SetPoint(6,3000,0.6484384537);
   graph->SetPoint(7,3250,0.6475678086);
   graph->SetPoint(8,3500,0.6445054412);
   
   TH1F *Graph_Graph15 = new TH1F("Graph_Graph15","Graph",100,1300,3700);
   Graph_Graph15->SetMinimum(0.5440632);
   Graph_Graph15->SetMaximum(0.6638767);
   Graph_Graph15->SetDirectory(0);
   Graph_Graph15->SetStats(0);
   Graph_Graph15->SetLineWidth(2);
   Graph_Graph15->SetMarkerStyle(8);
   Graph_Graph15->SetMarkerSize(0.8);
   Graph_Graph15->GetXaxis()->SetNdivisions(506);
   Graph_Graph15->GetXaxis()->SetLabelFont(42);
   Graph_Graph15->GetXaxis()->SetLabelSize(0.073);
   Graph_Graph15->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph15->GetXaxis()->SetTitleFont(42);
   Graph_Graph15->GetYaxis()->SetNdivisions(506);
   Graph_Graph15->GetYaxis()->SetLabelFont(42);
   Graph_Graph15->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph15->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph15->GetYaxis()->SetTitleFont(42);
   Graph_Graph15->GetZaxis()->SetLabelFont(42);
   Graph_Graph15->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph15->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph15->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph15);
   
   multigraph->Add(graph,"l");
   
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
   graph->SetPoint(0,750,0.3678229749);
   graph->SetPoint(1,1000,0.4173913002);
   graph->SetPoint(2,1250,0.4620263278);
   graph->SetPoint(3,1500,0.4936271608);
   graph->SetPoint(4,1750,0.5291640162);
   graph->SetPoint(5,2000,0.560743928);
   graph->SetPoint(6,2250,0.5801804066);
   graph->SetPoint(7,2500,0.5870440602);
   graph->SetPoint(8,3000,0.5955486298);
   
   TH1F *Graph_Graph16 = new TH1F("Graph_Graph16","Graph",100,525,3225);
   Graph_Graph16->SetMinimum(0.3450504);
   Graph_Graph16->SetMaximum(0.6183212);
   Graph_Graph16->SetDirectory(0);
   Graph_Graph16->SetStats(0);
   Graph_Graph16->SetLineWidth(2);
   Graph_Graph16->SetMarkerStyle(8);
   Graph_Graph16->SetMarkerSize(0.8);
   Graph_Graph16->GetXaxis()->SetNdivisions(506);
   Graph_Graph16->GetXaxis()->SetLabelFont(42);
   Graph_Graph16->GetXaxis()->SetLabelSize(0.073);
   Graph_Graph16->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph16->GetXaxis()->SetTitleFont(42);
   Graph_Graph16->GetYaxis()->SetNdivisions(506);
   Graph_Graph16->GetYaxis()->SetLabelFont(42);
   Graph_Graph16->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph16->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph16->GetYaxis()->SetTitleFont(42);
   Graph_Graph16->GetZaxis()->SetLabelFont(42);
   Graph_Graph16->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph16->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph16->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph16);
   
   multigraph->Add(graph,"l");
   
   graph = new TGraph(8);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineColor(4);
   graph->SetLineStyle(2);
   graph->SetLineWidth(2);
   graph->SetMarkerColor(4);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(0.8);
   graph->SetPoint(0,1250,0.4672647417);
   graph->SetPoint(1,1500,0.50480479);
   graph->SetPoint(2,1750,0.5310369134);
   graph->SetPoint(3,2000,0.5592991114);
   graph->SetPoint(4,2250,0.5783074498);
   graph->SetPoint(5,2500,0.5910410881);
   graph->SetPoint(6,2750,0.5932534337);
   graph->SetPoint(7,3000,0.6007168293);
   
   TH1F *Graph_Graph17 = new TH1F("Graph_Graph17","Graph",100,1075,3175);
   Graph_Graph17->SetMinimum(0.4539195);
   Graph_Graph17->SetMaximum(0.614062);
   Graph_Graph17->SetDirectory(0);
   Graph_Graph17->SetStats(0);
   Graph_Graph17->SetLineWidth(2);
   Graph_Graph17->SetMarkerStyle(8);
   Graph_Graph17->SetMarkerSize(0.8);
   Graph_Graph17->GetXaxis()->SetNdivisions(506);
   Graph_Graph17->GetXaxis()->SetLabelFont(42);
   Graph_Graph17->GetXaxis()->SetLabelSize(0.073);
   Graph_Graph17->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph17->GetXaxis()->SetTitleFont(42);
   Graph_Graph17->GetYaxis()->SetNdivisions(506);
   Graph_Graph17->GetYaxis()->SetLabelFont(42);
   Graph_Graph17->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph17->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph17->GetYaxis()->SetTitleFont(42);
   Graph_Graph17->GetZaxis()->SetLabelFont(42);
   Graph_Graph17->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph17->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph17->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph17);
   
   multigraph->Add(graph,"l");
   
   graph = new TGraph(9);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineColor(8);
   graph->SetLineStyle(2);
   graph->SetLineWidth(2);
   graph->SetMarkerColor(8);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(0.8);
   graph->SetPoint(0,1500,0.499246031);
   graph->SetPoint(1,1750,0.5325105786);
   graph->SetPoint(2,2000,0.5597882271);
   graph->SetPoint(3,2250,0.5750228167);
   graph->SetPoint(4,2500,0.5917764306);
   graph->SetPoint(5,2750,0.5929740667);
   graph->SetPoint(6,3000,0.5879302621);
   graph->SetPoint(7,3250,0.5894337893);
   graph->SetPoint(8,3500,0.5883265734);
   
   TH1F *Graph_Graph18 = new TH1F("Graph_Graph18","Graph",100,1300,3700);
   Graph_Graph18->SetMinimum(0.4898732);
   Graph_Graph18->SetMaximum(0.6023469);
   Graph_Graph18->SetDirectory(0);
   Graph_Graph18->SetStats(0);
   Graph_Graph18->SetLineWidth(2);
   Graph_Graph18->SetMarkerStyle(8);
   Graph_Graph18->SetMarkerSize(0.8);
   Graph_Graph18->GetXaxis()->SetNdivisions(506);
   Graph_Graph18->GetXaxis()->SetLabelFont(42);
   Graph_Graph18->GetXaxis()->SetLabelSize(0.073);
   Graph_Graph18->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph18->GetXaxis()->SetTitleFont(42);
   Graph_Graph18->GetYaxis()->SetNdivisions(506);
   Graph_Graph18->GetYaxis()->SetLabelFont(42);
   Graph_Graph18->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph18->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph18->GetYaxis()->SetTitleFont(42);
   Graph_Graph18->GetZaxis()->SetLabelFont(42);
   Graph_Graph18->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph18->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph18->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph18);
   
   multigraph->Add(graph,"l");
   
   graph = new TGraph(9);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   graph->SetMarkerColor(2);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(0.8);
   graph->SetPoint(0,750,0.2950558066);
   graph->SetPoint(1,1000,0.3356202543);
   graph->SetPoint(2,1250,0.375349015);
   graph->SetPoint(3,1500,0.4058765173);
   graph->SetPoint(4,1750,0.433288306);
   graph->SetPoint(5,2000,0.460328877);
   graph->SetPoint(6,2250,0.4802043438);
   graph->SetPoint(7,2500,0.4809248447);
   graph->SetPoint(8,3000,0.490088135);
   
   TH1F *Graph_Graph19 = new TH1F("Graph_Graph19","Graph",100,525,3225);
   Graph_Graph19->SetMinimum(0.2755526);
   Graph_Graph19->SetMaximum(0.5095914);
   Graph_Graph19->SetDirectory(0);
   Graph_Graph19->SetStats(0);
   Graph_Graph19->SetLineWidth(2);
   Graph_Graph19->SetMarkerStyle(8);
   Graph_Graph19->SetMarkerSize(0.8);
   Graph_Graph19->GetXaxis()->SetNdivisions(506);
   Graph_Graph19->GetXaxis()->SetLabelFont(42);
   Graph_Graph19->GetXaxis()->SetLabelSize(0.073);
   Graph_Graph19->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph19->GetXaxis()->SetTitleFont(42);
   Graph_Graph19->GetYaxis()->SetNdivisions(506);
   Graph_Graph19->GetYaxis()->SetLabelFont(42);
   Graph_Graph19->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph19->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph19->GetYaxis()->SetTitleFont(42);
   Graph_Graph19->GetZaxis()->SetLabelFont(42);
   Graph_Graph19->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph19->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph19->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph19);
   
   multigraph->Add(graph,"l");
   
   graph = new TGraph(8);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   graph->SetMarkerColor(4);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(0.8);
   graph->SetPoint(0,1250,0.3783891499);
   graph->SetPoint(1,1500,0.4101439416);
   graph->SetPoint(2,1750,0.4339622557);
   graph->SetPoint(3,2000,0.4567503035);
   graph->SetPoint(4,2250,0.4752839506);
   graph->SetPoint(5,2500,0.4862553179);
   graph->SetPoint(6,2750,0.4899040163);
   graph->SetPoint(7,3000,0.497929126);
   
   TH1F *Graph_Graph20 = new TH1F("Graph_Graph20","Graph",100,1075,3175);
   Graph_Graph20->SetMinimum(0.3664352);
   Graph_Graph20->SetMaximum(0.5098831);
   Graph_Graph20->SetDirectory(0);
   Graph_Graph20->SetStats(0);
   Graph_Graph20->SetLineWidth(2);
   Graph_Graph20->SetMarkerStyle(8);
   Graph_Graph20->SetMarkerSize(0.8);
   Graph_Graph20->GetXaxis()->SetNdivisions(506);
   Graph_Graph20->GetXaxis()->SetLabelFont(42);
   Graph_Graph20->GetXaxis()->SetLabelSize(0.073);
   Graph_Graph20->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph20->GetXaxis()->SetTitleFont(42);
   Graph_Graph20->GetYaxis()->SetNdivisions(506);
   Graph_Graph20->GetYaxis()->SetLabelFont(42);
   Graph_Graph20->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph20->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph20->GetYaxis()->SetTitleFont(42);
   Graph_Graph20->GetZaxis()->SetLabelFont(42);
   Graph_Graph20->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph20->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph20->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph20);
   
   multigraph->Add(graph,"l");
   
   graph = new TGraph(9);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineColor(8);
   graph->SetLineWidth(2);
   graph->SetMarkerColor(8);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(0.8);
   graph->SetPoint(0,1500,0.4086111188);
   graph->SetPoint(1,1750,0.4314242303);
   graph->SetPoint(2,2000,0.4584428072);
   graph->SetPoint(3,2250,0.4729155898);
   graph->SetPoint(4,2500,0.4871057868);
   graph->SetPoint(5,2750,0.4875848293);
   graph->SetPoint(6,3000,0.4890909791);
   graph->SetPoint(7,3250,0.4878389239);
   graph->SetPoint(8,3500,0.4881435633);
   
   TH1F *Graph_Graph21 = new TH1F("Graph_Graph21","Graph",100,1300,3700);
   Graph_Graph21->SetMinimum(0.4005631);
   Graph_Graph21->SetMaximum(0.497139);
   Graph_Graph21->SetDirectory(0);
   Graph_Graph21->SetStats(0);
   Graph_Graph21->SetLineWidth(2);
   Graph_Graph21->SetMarkerStyle(8);
   Graph_Graph21->SetMarkerSize(0.8);
   Graph_Graph21->GetXaxis()->SetNdivisions(506);
   Graph_Graph21->GetXaxis()->SetLabelFont(42);
   Graph_Graph21->GetXaxis()->SetLabelSize(0.073);
   Graph_Graph21->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph21->GetXaxis()->SetTitleFont(42);
   Graph_Graph21->GetYaxis()->SetNdivisions(506);
   Graph_Graph21->GetYaxis()->SetLabelFont(42);
   Graph_Graph21->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph21->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph21->GetYaxis()->SetTitleFont(42);
   Graph_Graph21->GetZaxis()->SetLabelFont(42);
   Graph_Graph21->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph21->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph21->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph21);
   
   multigraph->Add(graph,"l");
   multigraph->Draw("L");
   
   TLegend *leg = new TLegend(0.42,0.2,0.73,0.4,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("Graph","Loose PFID #tilde{k} = 0.01","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(3);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("Graph","Loose PFID #tilde{k} = 0.05","l");
   entry->SetLineColor(4);
   entry->SetLineStyle(3);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("Graph","Loose PFID #tilde{k} = 0.1","l");
   entry->SetLineColor(8);
   entry->SetLineStyle(3);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("Graph","Med PFID #tilde{k} = 0.01","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("Graph","Med PFID #tilde{k} = 0.05","l");
   entry->SetLineColor(4);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("Graph","Med PFID #tilde{k} = 0.1","l");
   entry->SetLineColor(8);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("Graph","iIght PFID #tilde{k} = 0.01","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("Graph","iIght PFID #tilde{k} = 0.05","l");
   entry->SetLineColor(4);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("Graph","iIght PFID #tilde{k} = 0.1","l");
   entry->SetLineColor(8);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   leg->Draw();
   
   TH1F *test__3 = new TH1F("test__3","",10,750,3500);
   test__3->SetMinimum(0.2);
   test__3->SetMaximum(0.7);
   test__3->SetDirectory(0);
   test__3->SetStats(0);
   test__3->SetLineWidth(2);
   test__3->SetMarkerStyle(8);
   test__3->SetMarkerSize(0.8);
   test__3->GetXaxis()->SetTitle("M_{1} [GeV]");
   test__3->GetXaxis()->SetNdivisions(506);
   test__3->GetXaxis()->SetLabelFont(42);
   test__3->GetXaxis()->SetTitleOffset(1.2);
   test__3->GetXaxis()->SetTitleFont(42);
   test__3->GetYaxis()->SetTitle("efficiency*acceptance");
   test__3->GetYaxis()->SetNdivisions(506);
   test__3->GetYaxis()->SetLabelFont(42);
   test__3->GetYaxis()->SetTitleOffset(1.2);
   test__3->GetYaxis()->SetTitleFont(42);
   test__3->GetZaxis()->SetLabelFont(42);
   test__3->GetZaxis()->SetTitleSize(0.06);
   test__3->GetZaxis()->SetTitleOffset(1.1);
   test__3->GetZaxis()->SetTitleFont(42);
   test__3->Draw("sameaxis");
   c1_n5->Modified();
   c1_n5->cd();
   c1_n5->SetSelected(c1_n5);
}
