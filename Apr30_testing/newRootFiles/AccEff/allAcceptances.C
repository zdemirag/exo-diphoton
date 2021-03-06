{
//=========Macro generated from canvas: c1_n5/c1_n5
//=========  (Thu Dec 19 14:52:54 2013) by ROOT version5.32/00
   TCanvas *c1_n5 = new TCanvas("c1_n5", "c1_n5",0,0,700,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   c1_n5->SetHighLightColor(2);
   c1_n5->Range(229.7297,-0.1948052,3945.946,1.103896);
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
   test->SetMinimum(0);
   test->SetMaximum(1);
   test->SetStats(0);
   test->SetLineWidth(2);
   test->SetMarkerStyle(8);
   test->SetMarkerSize(0.8);
   test->GetXaxis()->SetTitle("M_{1} [GeV]");
   test->GetXaxis()->SetNdivisions(506);
   test->GetXaxis()->SetLabelFont(42);
   test->GetXaxis()->SetTitleOffset(1.2);
   test->GetXaxis()->SetTitleFont(42);
   test->GetYaxis()->SetTitle("acceptance");
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
   graph->SetLineWidth(2);
   graph->SetMarkerColor(2);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(0.8);
   graph->SetPoint(0,750,0.5071770549);
   graph->SetPoint(1,1000,0.5796569586);
   graph->SetPoint(2,1250,0.637694478);
   graph->SetPoint(3,1500,0.6863609552);
   graph->SetPoint(4,1750,0.7396694422);
   graph->SetPoint(5,2000,0.7813298106);
   graph->SetPoint(6,2250,0.8147349954);
   graph->SetPoint(7,2500,0.8279848695);
   graph->SetPoint(8,3000,0.8708866835);
   
   TH1F *Graph_Graph10 = new TH1F("Graph_Graph10","Graph",100,525,3225);
   Graph_Graph10->SetMinimum(0.4708061);
   Graph_Graph10->SetMaximum(0.9072576);
   Graph_Graph10->SetDirectory(0);
   Graph_Graph10->SetStats(0);
   Graph_Graph10->SetLineWidth(2);
   Graph_Graph10->SetMarkerStyle(8);
   Graph_Graph10->SetMarkerSize(0.8);
   Graph_Graph10->GetXaxis()->SetNdivisions(506);
   Graph_Graph10->GetXaxis()->SetLabelFont(42);
   Graph_Graph10->GetXaxis()->SetLabelSize(0.073);
   Graph_Graph10->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph10->GetXaxis()->SetTitleFont(42);
   Graph_Graph10->GetYaxis()->SetNdivisions(506);
   Graph_Graph10->GetYaxis()->SetLabelFont(42);
   Graph_Graph10->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph10->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph10->GetYaxis()->SetTitleFont(42);
   Graph_Graph10->GetZaxis()->SetLabelFont(42);
   Graph_Graph10->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph10->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph10->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph10);
   
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
   graph->SetPoint(0,1250,0.6439393759);
   graph->SetPoint(1,1500,0.6942062974);
   graph->SetPoint(2,1750,0.7340256572);
   graph->SetPoint(3,2000,0.7837514877);
   graph->SetPoint(4,2250,0.8051911592);
   graph->SetPoint(5,2500,0.8333134651);
   graph->SetPoint(6,2750,0.8518061042);
   graph->SetPoint(7,3000,0.8652330041);
   
   TH1F *Graph_Graph11 = new TH1F("Graph_Graph11","Graph",100,1075,3175);
   Graph_Graph11->SetMinimum(0.62181);
   Graph_Graph11->SetMaximum(0.8873624);
   Graph_Graph11->SetDirectory(0);
   Graph_Graph11->SetStats(0);
   Graph_Graph11->SetLineWidth(2);
   Graph_Graph11->SetMarkerStyle(8);
   Graph_Graph11->SetMarkerSize(0.8);
   Graph_Graph11->GetXaxis()->SetNdivisions(506);
   Graph_Graph11->GetXaxis()->SetLabelFont(42);
   Graph_Graph11->GetXaxis()->SetLabelSize(0.073);
   Graph_Graph11->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph11->GetXaxis()->SetTitleFont(42);
   Graph_Graph11->GetYaxis()->SetNdivisions(506);
   Graph_Graph11->GetYaxis()->SetLabelFont(42);
   Graph_Graph11->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph11->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph11->GetYaxis()->SetTitleFont(42);
   Graph_Graph11->GetZaxis()->SetLabelFont(42);
   Graph_Graph11->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph11->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph11->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph11);
   
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
   graph->SetPoint(0,1500,0.6922222376);
   graph->SetPoint(1,1750,0.736959815);
   graph->SetPoint(2,2000,0.7774858475);
   graph->SetPoint(3,2250,0.8054684997);
   graph->SetPoint(4,2500,0.8271057606);
   graph->SetPoint(5,2750,0.8473054171);
   graph->SetPoint(6,3000,0.8621116281);
   graph->SetPoint(7,3250,0.8769139051);
   graph->SetPoint(8,3500,0.8859314322);
   
   TH1F *Graph_Graph12 = new TH1F("Graph_Graph12","Graph",100,1300,3700);
   Graph_Graph12->SetMinimum(0.6728513);
   Graph_Graph12->SetMaximum(0.9053024);
   Graph_Graph12->SetDirectory(0);
   Graph_Graph12->SetStats(0);
   Graph_Graph12->SetLineWidth(2);
   Graph_Graph12->SetMarkerStyle(8);
   Graph_Graph12->SetMarkerSize(0.8);
   Graph_Graph12->GetXaxis()->SetNdivisions(506);
   Graph_Graph12->GetXaxis()->SetLabelFont(42);
   Graph_Graph12->GetXaxis()->SetLabelSize(0.073);
   Graph_Graph12->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph12->GetXaxis()->SetTitleFont(42);
   Graph_Graph12->GetYaxis()->SetNdivisions(506);
   Graph_Graph12->GetYaxis()->SetLabelFont(42);
   Graph_Graph12->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph12->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph12->GetYaxis()->SetTitleFont(42);
   Graph_Graph12->GetZaxis()->SetLabelFont(42);
   Graph_Graph12->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph12->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph12->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph12);
   
   multigraph->Add(graph,"l");
   multigraph->Draw("L");
   
   TLegend *leg = new TLegend(0.3,0.175,0.85,0.35,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("Graph","#tilde{k} = 0.01","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("Graph","#tilde{k} = 0.05","l");
   entry->SetLineColor(4);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("Graph","#tilde{k} = 0.1","l");
   entry->SetLineColor(8);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   leg->Draw();
   
   TH1F *test__2 = new TH1F("test__2","",10,750,3500);
   test__2->SetMinimum(0);
   test__2->SetMaximum(1);
   test__2->SetDirectory(0);
   test__2->SetStats(0);
   test__2->SetLineWidth(2);
   test__2->SetMarkerStyle(8);
   test__2->SetMarkerSize(0.8);
   test__2->GetXaxis()->SetTitle("M_{1} [GeV]");
   test__2->GetXaxis()->SetNdivisions(506);
   test__2->GetXaxis()->SetLabelFont(42);
   test__2->GetXaxis()->SetTitleOffset(1.2);
   test__2->GetXaxis()->SetTitleFont(42);
   test__2->GetYaxis()->SetTitle("acceptance");
   test__2->GetYaxis()->SetNdivisions(506);
   test__2->GetYaxis()->SetLabelFont(42);
   test__2->GetYaxis()->SetTitleOffset(1.2);
   test__2->GetYaxis()->SetTitleFont(42);
   test__2->GetZaxis()->SetLabelFont(42);
   test__2->GetZaxis()->SetTitleSize(0.06);
   test__2->GetZaxis()->SetTitleOffset(1.1);
   test__2->GetZaxis()->SetTitleFont(42);
   test__2->Draw("sameaxis");
   c1_n5->Modified();
   c1_n5->cd();
   c1_n5->SetSelected(c1_n5);
}
