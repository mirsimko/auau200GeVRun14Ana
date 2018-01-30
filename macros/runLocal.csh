#!/bin/csh

# starver SL16j
starver SL18a

root -l -b -q StRoot/macros/loadSharedHFLibraries.C 'StRoot/macros/runPicoHFLambdaCMaker.C++g("test_pico.list","output_new_final_test",0,"BadRunList_MB.list","LambdaC_kPionKaonProton_picoHFtree","root://xrdstar.rcf.bnl.gov:1095//home/starlib/home/starreco/reco/AuAu_200_production_2016/ReversedFullField/P16ij/2016",0)'
