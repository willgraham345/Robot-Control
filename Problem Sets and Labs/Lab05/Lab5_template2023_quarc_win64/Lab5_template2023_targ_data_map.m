    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 10;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (Lab5_template2023_P)
        ;%
            section.nData     = 18;
            section.data(18)  = dumData; %prealloc

                    ;% Lab5_template2023_P.PDController_D
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Lab5_template2023_P.PDController_InitialConditionFo
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% Lab5_template2023_P.PDController_N
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 3;

                    ;% Lab5_template2023_P.PDController_P
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 4;

                    ;% Lab5_template2023_P.BiasRemoval_end_time
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 6;

                    ;% Lab5_template2023_P.BiasRemoval1_end_time
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 7;

                    ;% Lab5_template2023_P.SecondOrderLowPassFilter_input_
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 8;

                    ;% Lab5_template2023_P.SecondOrderLowPassFilter1_input
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 9;

                    ;% Lab5_template2023_P.SecondOrderLowPassFilter_inpu_o
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 10;

                    ;% Lab5_template2023_P.SecondOrderLowPassFilter1_inp_b
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 11;

                    ;% Lab5_template2023_P.XYSuperimposed_maximum_x
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 12;

                    ;% Lab5_template2023_P.XYSuperimposed_maximum_y
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 13;

                    ;% Lab5_template2023_P.XYSuperimposed_minimum_x
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 14;

                    ;% Lab5_template2023_P.XYSuperimposed_minimum_y
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 15;

                    ;% Lab5_template2023_P.BiasRemoval_start_time
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 16;

                    ;% Lab5_template2023_P.BiasRemoval1_start_time
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 17;

                    ;% Lab5_template2023_P.BiasRemoval_switch_id
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 18;

                    ;% Lab5_template2023_P.BiasRemoval1_switch_id
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 19;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Lab5_template2023_P.XYSuperimposed_update_rate
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Lab5_template2023_P.HILReadAnalog_channels
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

                    ;% Lab5_template2023_P.HILReadEncoder_channels
                    section.data(2).logicalSrcIdx = 20;
                    section.data(2).dtTransOffset = 2;

                    ;% Lab5_template2023_P.HILWriteAnalog_channels
                    section.data(3).logicalSrcIdx = 21;
                    section.data(3).dtTransOffset = 4;

                    ;% Lab5_template2023_P.HILReadAnalog_channels_c
                    section.data(4).logicalSrcIdx = 22;
                    section.data(4).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 45;
            section.data(45)  = dumData; %prealloc

                    ;% Lab5_template2023_P.HILInitialize_OOTerminate
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

                    ;% Lab5_template2023_P.HILInitialize_OOExit
                    section.data(2).logicalSrcIdx = 24;
                    section.data(2).dtTransOffset = 1;

                    ;% Lab5_template2023_P.HILInitialize_OOStart
                    section.data(3).logicalSrcIdx = 25;
                    section.data(3).dtTransOffset = 2;

                    ;% Lab5_template2023_P.HILInitialize_OOEnter
                    section.data(4).logicalSrcIdx = 26;
                    section.data(4).dtTransOffset = 3;

                    ;% Lab5_template2023_P.HILInitialize_AOFinal
                    section.data(5).logicalSrcIdx = 27;
                    section.data(5).dtTransOffset = 4;

                    ;% Lab5_template2023_P.HILInitialize_POFinal
                    section.data(6).logicalSrcIdx = 28;
                    section.data(6).dtTransOffset = 5;

                    ;% Lab5_template2023_P.HILInitialize_AIHigh
                    section.data(7).logicalSrcIdx = 29;
                    section.data(7).dtTransOffset = 6;

                    ;% Lab5_template2023_P.HILInitialize_AILow
                    section.data(8).logicalSrcIdx = 30;
                    section.data(8).dtTransOffset = 7;

                    ;% Lab5_template2023_P.HILInitialize_AOHigh
                    section.data(9).logicalSrcIdx = 31;
                    section.data(9).dtTransOffset = 8;

                    ;% Lab5_template2023_P.HILInitialize_AOLow
                    section.data(10).logicalSrcIdx = 32;
                    section.data(10).dtTransOffset = 9;

                    ;% Lab5_template2023_P.HILInitialize_AOInitial
                    section.data(11).logicalSrcIdx = 33;
                    section.data(11).dtTransOffset = 10;

                    ;% Lab5_template2023_P.HILInitialize_POFrequency
                    section.data(12).logicalSrcIdx = 34;
                    section.data(12).dtTransOffset = 11;

                    ;% Lab5_template2023_P.HILInitialize_POInitial
                    section.data(13).logicalSrcIdx = 35;
                    section.data(13).dtTransOffset = 12;

                    ;% Lab5_template2023_P.HILInitialize_OOTerminate_j
                    section.data(14).logicalSrcIdx = 36;
                    section.data(14).dtTransOffset = 13;

                    ;% Lab5_template2023_P.HILInitialize_OOExit_d
                    section.data(15).logicalSrcIdx = 37;
                    section.data(15).dtTransOffset = 14;

                    ;% Lab5_template2023_P.HILInitialize_OOStart_h
                    section.data(16).logicalSrcIdx = 38;
                    section.data(16).dtTransOffset = 15;

                    ;% Lab5_template2023_P.HILInitialize_OOEnter_i
                    section.data(17).logicalSrcIdx = 39;
                    section.data(17).dtTransOffset = 16;

                    ;% Lab5_template2023_P.HILInitialize_AOFinal_m
                    section.data(18).logicalSrcIdx = 40;
                    section.data(18).dtTransOffset = 17;

                    ;% Lab5_template2023_P.HILInitialize_POFinal_c
                    section.data(19).logicalSrcIdx = 41;
                    section.data(19).dtTransOffset = 18;

                    ;% Lab5_template2023_P.HILInitialize_AIHigh_p
                    section.data(20).logicalSrcIdx = 42;
                    section.data(20).dtTransOffset = 19;

                    ;% Lab5_template2023_P.HILInitialize_AILow_m
                    section.data(21).logicalSrcIdx = 43;
                    section.data(21).dtTransOffset = 20;

                    ;% Lab5_template2023_P.HILInitialize_AOHigh_n
                    section.data(22).logicalSrcIdx = 44;
                    section.data(22).dtTransOffset = 21;

                    ;% Lab5_template2023_P.HILInitialize_AOLow_n
                    section.data(23).logicalSrcIdx = 45;
                    section.data(23).dtTransOffset = 22;

                    ;% Lab5_template2023_P.HILInitialize_AOInitial_b
                    section.data(24).logicalSrcIdx = 46;
                    section.data(24).dtTransOffset = 23;

                    ;% Lab5_template2023_P.HILInitialize_AOWatchdog
                    section.data(25).logicalSrcIdx = 47;
                    section.data(25).dtTransOffset = 24;

                    ;% Lab5_template2023_P.HILInitialize_POFrequency_c
                    section.data(26).logicalSrcIdx = 48;
                    section.data(26).dtTransOffset = 25;

                    ;% Lab5_template2023_P.HILInitialize_POLeading
                    section.data(27).logicalSrcIdx = 49;
                    section.data(27).dtTransOffset = 26;

                    ;% Lab5_template2023_P.HILInitialize_POTrailing
                    section.data(28).logicalSrcIdx = 50;
                    section.data(28).dtTransOffset = 27;

                    ;% Lab5_template2023_P.HILInitialize_POInitial_g
                    section.data(29).logicalSrcIdx = 51;
                    section.data(29).dtTransOffset = 28;

                    ;% Lab5_template2023_P.HILInitialize_POWatchdog
                    section.data(30).logicalSrcIdx = 52;
                    section.data(30).dtTransOffset = 29;

                    ;% Lab5_template2023_P.XGainNV_Gain
                    section.data(31).logicalSrcIdx = 53;
                    section.data(31).dtTransOffset = 30;

                    ;% Lab5_template2023_P.YGainNV_Gain
                    section.data(32).logicalSrcIdx = 54;
                    section.data(32).dtTransOffset = 31;

                    ;% Lab5_template2023_P.Constant_Value
                    section.data(33).logicalSrcIdx = 55;
                    section.data(33).dtTransOffset = 32;

                    ;% Lab5_template2023_P.x0_Value
                    section.data(34).logicalSrcIdx = 56;
                    section.data(34).dtTransOffset = 33;

                    ;% Lab5_template2023_P.Integrator2_IC
                    section.data(35).logicalSrcIdx = 57;
                    section.data(35).dtTransOffset = 34;

                    ;% Lab5_template2023_P.Constant_Value_m
                    section.data(36).logicalSrcIdx = 58;
                    section.data(36).dtTransOffset = 35;

                    ;% Lab5_template2023_P.x0_Value_a
                    section.data(37).logicalSrcIdx = 59;
                    section.data(37).dtTransOffset = 36;

                    ;% Lab5_template2023_P.Integrator2_IC_p
                    section.data(38).logicalSrcIdx = 60;
                    section.data(38).dtTransOffset = 37;

                    ;% Lab5_template2023_P.HomePosition_Value
                    section.data(39).logicalSrcIdx = 61;
                    section.data(39).dtTransOffset = 38;

                    ;% Lab5_template2023_P.EncoderGain_Gain
                    section.data(40).logicalSrcIdx = 62;
                    section.data(40).dtTransOffset = 40;

                    ;% Lab5_template2023_P.Speed_Value
                    section.data(41).logicalSrcIdx = 63;
                    section.data(41).dtTransOffset = 42;

                    ;% Lab5_template2023_P.invmotorgain_Gain
                    section.data(42).logicalSrcIdx = 64;
                    section.data(42).dtTransOffset = 43;

                    ;% Lab5_template2023_P.AmpBiasTuneforeachampifneeded_B
                    section.data(43).logicalSrcIdx = 65;
                    section.data(43).dtTransOffset = 44;

                    ;% Lab5_template2023_P.uAmpGain_Gain
                    section.data(44).logicalSrcIdx = 66;
                    section.data(44).dtTransOffset = 46;

                    ;% Lab5_template2023_P.uSenseGain_Gain
                    section.data(45).logicalSrcIdx = 67;
                    section.data(45).dtTransOffset = 48;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% Lab5_template2023_P.HILInitialize_EIInitial
                    section.data(1).logicalSrcIdx = 68;
                    section.data(1).dtTransOffset = 0;

                    ;% Lab5_template2023_P.HILInitialize_POModes
                    section.data(2).logicalSrcIdx = 69;
                    section.data(2).dtTransOffset = 1;

                    ;% Lab5_template2023_P.HILInitialize_CKChannels
                    section.data(3).logicalSrcIdx = 70;
                    section.data(3).dtTransOffset = 2;

                    ;% Lab5_template2023_P.HILInitialize_DOWatchdog
                    section.data(4).logicalSrcIdx = 71;
                    section.data(4).dtTransOffset = 5;

                    ;% Lab5_template2023_P.HILInitialize_EIInitial_d
                    section.data(5).logicalSrcIdx = 72;
                    section.data(5).dtTransOffset = 6;

                    ;% Lab5_template2023_P.HILInitialize_POModes_k
                    section.data(6).logicalSrcIdx = 73;
                    section.data(6).dtTransOffset = 7;

                    ;% Lab5_template2023_P.HILInitialize_POConfiguration
                    section.data(7).logicalSrcIdx = 74;
                    section.data(7).dtTransOffset = 8;

                    ;% Lab5_template2023_P.HILInitialize_POAlignment
                    section.data(8).logicalSrcIdx = 75;
                    section.data(8).dtTransOffset = 9;

                    ;% Lab5_template2023_P.HILInitialize_POPolarity
                    section.data(9).logicalSrcIdx = 76;
                    section.data(9).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% Lab5_template2023_P.HILInitialize_AOChannels
                    section.data(1).logicalSrcIdx = 77;
                    section.data(1).dtTransOffset = 0;

                    ;% Lab5_template2023_P.HILInitialize_EIQuadrature
                    section.data(2).logicalSrcIdx = 78;
                    section.data(2).dtTransOffset = 1;

                    ;% Lab5_template2023_P.HILInitialize_AIChannels
                    section.data(3).logicalSrcIdx = 79;
                    section.data(3).dtTransOffset = 2;

                    ;% Lab5_template2023_P.HILInitialize_AOChannels_p
                    section.data(4).logicalSrcIdx = 80;
                    section.data(4).dtTransOffset = 10;

                    ;% Lab5_template2023_P.HILInitialize_EIChannels
                    section.data(5).logicalSrcIdx = 81;
                    section.data(5).dtTransOffset = 18;

                    ;% Lab5_template2023_P.HILInitialize_EIQuadrature_e
                    section.data(6).logicalSrcIdx = 82;
                    section.data(6).dtTransOffset = 26;

                    ;% Lab5_template2023_P.HILInitialize_POChannels
                    section.data(7).logicalSrcIdx = 83;
                    section.data(7).dtTransOffset = 27;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 74;
            section.data(74)  = dumData; %prealloc

                    ;% Lab5_template2023_P.HILInitialize_Active
                    section.data(1).logicalSrcIdx = 84;
                    section.data(1).dtTransOffset = 0;

                    ;% Lab5_template2023_P.HILInitialize_AOTerminate
                    section.data(2).logicalSrcIdx = 85;
                    section.data(2).dtTransOffset = 1;

                    ;% Lab5_template2023_P.HILInitialize_AOExit
                    section.data(3).logicalSrcIdx = 86;
                    section.data(3).dtTransOffset = 2;

                    ;% Lab5_template2023_P.HILInitialize_DOTerminate
                    section.data(4).logicalSrcIdx = 87;
                    section.data(4).dtTransOffset = 3;

                    ;% Lab5_template2023_P.HILInitialize_DOExit
                    section.data(5).logicalSrcIdx = 88;
                    section.data(5).dtTransOffset = 4;

                    ;% Lab5_template2023_P.HILInitialize_POTerminate
                    section.data(6).logicalSrcIdx = 89;
                    section.data(6).dtTransOffset = 5;

                    ;% Lab5_template2023_P.HILInitialize_POExit
                    section.data(7).logicalSrcIdx = 90;
                    section.data(7).dtTransOffset = 6;

                    ;% Lab5_template2023_P.HILInitialize_CKPStart
                    section.data(8).logicalSrcIdx = 91;
                    section.data(8).dtTransOffset = 7;

                    ;% Lab5_template2023_P.HILInitialize_CKPEnter
                    section.data(9).logicalSrcIdx = 92;
                    section.data(9).dtTransOffset = 8;

                    ;% Lab5_template2023_P.HILInitialize_CKStart
                    section.data(10).logicalSrcIdx = 93;
                    section.data(10).dtTransOffset = 9;

                    ;% Lab5_template2023_P.HILInitialize_CKEnter
                    section.data(11).logicalSrcIdx = 94;
                    section.data(11).dtTransOffset = 10;

                    ;% Lab5_template2023_P.HILInitialize_AIPStart
                    section.data(12).logicalSrcIdx = 95;
                    section.data(12).dtTransOffset = 11;

                    ;% Lab5_template2023_P.HILInitialize_AIPEnter
                    section.data(13).logicalSrcIdx = 96;
                    section.data(13).dtTransOffset = 12;

                    ;% Lab5_template2023_P.HILInitialize_AOPStart
                    section.data(14).logicalSrcIdx = 97;
                    section.data(14).dtTransOffset = 13;

                    ;% Lab5_template2023_P.HILInitialize_AOPEnter
                    section.data(15).logicalSrcIdx = 98;
                    section.data(15).dtTransOffset = 14;

                    ;% Lab5_template2023_P.HILInitialize_AOStart
                    section.data(16).logicalSrcIdx = 99;
                    section.data(16).dtTransOffset = 15;

                    ;% Lab5_template2023_P.HILInitialize_AOEnter
                    section.data(17).logicalSrcIdx = 100;
                    section.data(17).dtTransOffset = 16;

                    ;% Lab5_template2023_P.HILInitialize_AOReset
                    section.data(18).logicalSrcIdx = 101;
                    section.data(18).dtTransOffset = 17;

                    ;% Lab5_template2023_P.HILInitialize_DOPStart
                    section.data(19).logicalSrcIdx = 102;
                    section.data(19).dtTransOffset = 18;

                    ;% Lab5_template2023_P.HILInitialize_DOPEnter
                    section.data(20).logicalSrcIdx = 103;
                    section.data(20).dtTransOffset = 19;

                    ;% Lab5_template2023_P.HILInitialize_DOStart
                    section.data(21).logicalSrcIdx = 104;
                    section.data(21).dtTransOffset = 20;

                    ;% Lab5_template2023_P.HILInitialize_DOEnter
                    section.data(22).logicalSrcIdx = 105;
                    section.data(22).dtTransOffset = 21;

                    ;% Lab5_template2023_P.HILInitialize_DOReset
                    section.data(23).logicalSrcIdx = 106;
                    section.data(23).dtTransOffset = 22;

                    ;% Lab5_template2023_P.HILInitialize_EIPStart
                    section.data(24).logicalSrcIdx = 107;
                    section.data(24).dtTransOffset = 23;

                    ;% Lab5_template2023_P.HILInitialize_EIPEnter
                    section.data(25).logicalSrcIdx = 108;
                    section.data(25).dtTransOffset = 24;

                    ;% Lab5_template2023_P.HILInitialize_EIStart
                    section.data(26).logicalSrcIdx = 109;
                    section.data(26).dtTransOffset = 25;

                    ;% Lab5_template2023_P.HILInitialize_EIEnter
                    section.data(27).logicalSrcIdx = 110;
                    section.data(27).dtTransOffset = 26;

                    ;% Lab5_template2023_P.HILInitialize_POPStart
                    section.data(28).logicalSrcIdx = 111;
                    section.data(28).dtTransOffset = 27;

                    ;% Lab5_template2023_P.HILInitialize_POPEnter
                    section.data(29).logicalSrcIdx = 112;
                    section.data(29).dtTransOffset = 28;

                    ;% Lab5_template2023_P.HILInitialize_POStart
                    section.data(30).logicalSrcIdx = 113;
                    section.data(30).dtTransOffset = 29;

                    ;% Lab5_template2023_P.HILInitialize_POEnter
                    section.data(31).logicalSrcIdx = 114;
                    section.data(31).dtTransOffset = 30;

                    ;% Lab5_template2023_P.HILInitialize_POReset
                    section.data(32).logicalSrcIdx = 115;
                    section.data(32).dtTransOffset = 31;

                    ;% Lab5_template2023_P.HILInitialize_OOReset
                    section.data(33).logicalSrcIdx = 116;
                    section.data(33).dtTransOffset = 32;

                    ;% Lab5_template2023_P.HILInitialize_DOFinal
                    section.data(34).logicalSrcIdx = 117;
                    section.data(34).dtTransOffset = 33;

                    ;% Lab5_template2023_P.HILInitialize_DOInitial
                    section.data(35).logicalSrcIdx = 118;
                    section.data(35).dtTransOffset = 34;

                    ;% Lab5_template2023_P.HILInitialize_Active_e
                    section.data(36).logicalSrcIdx = 119;
                    section.data(36).dtTransOffset = 35;

                    ;% Lab5_template2023_P.HILInitialize_AOTerminate_g
                    section.data(37).logicalSrcIdx = 120;
                    section.data(37).dtTransOffset = 36;

                    ;% Lab5_template2023_P.HILInitialize_AOExit_e
                    section.data(38).logicalSrcIdx = 121;
                    section.data(38).dtTransOffset = 37;

                    ;% Lab5_template2023_P.HILInitialize_DOTerminate_c
                    section.data(39).logicalSrcIdx = 122;
                    section.data(39).dtTransOffset = 38;

                    ;% Lab5_template2023_P.HILInitialize_DOExit_m
                    section.data(40).logicalSrcIdx = 123;
                    section.data(40).dtTransOffset = 39;

                    ;% Lab5_template2023_P.HILInitialize_POTerminate_a
                    section.data(41).logicalSrcIdx = 124;
                    section.data(41).dtTransOffset = 40;

                    ;% Lab5_template2023_P.HILInitialize_POExit_l
                    section.data(42).logicalSrcIdx = 125;
                    section.data(42).dtTransOffset = 41;

                    ;% Lab5_template2023_P.HILInitialize_CKPStart_b
                    section.data(43).logicalSrcIdx = 126;
                    section.data(43).dtTransOffset = 42;

                    ;% Lab5_template2023_P.HILInitialize_CKPEnter_o
                    section.data(44).logicalSrcIdx = 127;
                    section.data(44).dtTransOffset = 43;

                    ;% Lab5_template2023_P.HILInitialize_CKStart_i
                    section.data(45).logicalSrcIdx = 128;
                    section.data(45).dtTransOffset = 44;

                    ;% Lab5_template2023_P.HILInitialize_CKEnter_p
                    section.data(46).logicalSrcIdx = 129;
                    section.data(46).dtTransOffset = 45;

                    ;% Lab5_template2023_P.HILInitialize_AIPStart_j
                    section.data(47).logicalSrcIdx = 130;
                    section.data(47).dtTransOffset = 46;

                    ;% Lab5_template2023_P.HILInitialize_AIPEnter_e
                    section.data(48).logicalSrcIdx = 131;
                    section.data(48).dtTransOffset = 47;

                    ;% Lab5_template2023_P.HILInitialize_AOPStart_b
                    section.data(49).logicalSrcIdx = 132;
                    section.data(49).dtTransOffset = 48;

                    ;% Lab5_template2023_P.HILInitialize_AOPEnter_p
                    section.data(50).logicalSrcIdx = 133;
                    section.data(50).dtTransOffset = 49;

                    ;% Lab5_template2023_P.HILInitialize_AOStart_k
                    section.data(51).logicalSrcIdx = 134;
                    section.data(51).dtTransOffset = 50;

                    ;% Lab5_template2023_P.HILInitialize_AOEnter_m
                    section.data(52).logicalSrcIdx = 135;
                    section.data(52).dtTransOffset = 51;

                    ;% Lab5_template2023_P.HILInitialize_AOReset_b
                    section.data(53).logicalSrcIdx = 136;
                    section.data(53).dtTransOffset = 52;

                    ;% Lab5_template2023_P.HILInitialize_DOPStart_m
                    section.data(54).logicalSrcIdx = 137;
                    section.data(54).dtTransOffset = 53;

                    ;% Lab5_template2023_P.HILInitialize_DOPEnter_m
                    section.data(55).logicalSrcIdx = 138;
                    section.data(55).dtTransOffset = 54;

                    ;% Lab5_template2023_P.HILInitialize_DOStart_e
                    section.data(56).logicalSrcIdx = 139;
                    section.data(56).dtTransOffset = 55;

                    ;% Lab5_template2023_P.HILInitialize_DOEnter_l
                    section.data(57).logicalSrcIdx = 140;
                    section.data(57).dtTransOffset = 56;

                    ;% Lab5_template2023_P.HILInitialize_DOReset_h
                    section.data(58).logicalSrcIdx = 141;
                    section.data(58).dtTransOffset = 57;

                    ;% Lab5_template2023_P.HILInitialize_EIPStart_j
                    section.data(59).logicalSrcIdx = 142;
                    section.data(59).dtTransOffset = 58;

                    ;% Lab5_template2023_P.HILInitialize_EIPEnter_i
                    section.data(60).logicalSrcIdx = 143;
                    section.data(60).dtTransOffset = 59;

                    ;% Lab5_template2023_P.HILInitialize_EIStart_a
                    section.data(61).logicalSrcIdx = 144;
                    section.data(61).dtTransOffset = 60;

                    ;% Lab5_template2023_P.HILInitialize_EIEnter_h
                    section.data(62).logicalSrcIdx = 145;
                    section.data(62).dtTransOffset = 61;

                    ;% Lab5_template2023_P.HILInitialize_POPStart_a
                    section.data(63).logicalSrcIdx = 146;
                    section.data(63).dtTransOffset = 62;

                    ;% Lab5_template2023_P.HILInitialize_POPEnter_b
                    section.data(64).logicalSrcIdx = 147;
                    section.data(64).dtTransOffset = 63;

                    ;% Lab5_template2023_P.HILInitialize_POStart_n
                    section.data(65).logicalSrcIdx = 148;
                    section.data(65).dtTransOffset = 64;

                    ;% Lab5_template2023_P.HILInitialize_POEnter_n
                    section.data(66).logicalSrcIdx = 149;
                    section.data(66).dtTransOffset = 65;

                    ;% Lab5_template2023_P.HILInitialize_POReset_d
                    section.data(67).logicalSrcIdx = 150;
                    section.data(67).dtTransOffset = 66;

                    ;% Lab5_template2023_P.HILInitialize_OOReset_p
                    section.data(68).logicalSrcIdx = 151;
                    section.data(68).dtTransOffset = 67;

                    ;% Lab5_template2023_P.HILInitialize_DOFinal_l
                    section.data(69).logicalSrcIdx = 152;
                    section.data(69).dtTransOffset = 68;

                    ;% Lab5_template2023_P.HILInitialize_DOInitial_d
                    section.data(70).logicalSrcIdx = 153;
                    section.data(70).dtTransOffset = 69;

                    ;% Lab5_template2023_P.HILReadAnalog_Active
                    section.data(71).logicalSrcIdx = 154;
                    section.data(71).dtTransOffset = 70;

                    ;% Lab5_template2023_P.HILReadEncoder_Active
                    section.data(72).logicalSrcIdx = 155;
                    section.data(72).dtTransOffset = 71;

                    ;% Lab5_template2023_P.HILWriteAnalog_Active
                    section.data(73).logicalSrcIdx = 156;
                    section.data(73).dtTransOffset = 72;

                    ;% Lab5_template2023_P.HILReadAnalog_Active_c
                    section.data(74).logicalSrcIdx = 157;
                    section.data(74).dtTransOffset = 73;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Lab5_template2023_P.XYSuperimposed_Mode
                    section.data(1).logicalSrcIdx = 158;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% Lab5_template2023_P.BiasRemoval1.x_avg_n_Y0
                    section.data(1).logicalSrcIdx = 159;
                    section.data(1).dtTransOffset = 0;

                    ;% Lab5_template2023_P.BiasRemoval1.unity_Value
                    section.data(2).logicalSrcIdx = 160;
                    section.data(2).dtTransOffset = 1;

                    ;% Lab5_template2023_P.BiasRemoval1.UnitDelay_InitialCondition
                    section.data(3).logicalSrcIdx = 161;
                    section.data(3).dtTransOffset = 2;

                    ;% Lab5_template2023_P.BiasRemoval1.Sumk1n1xk_InitialCondition
                    section.data(4).logicalSrcIdx = 162;
                    section.data(4).dtTransOffset = 3;

                    ;% Lab5_template2023_P.BiasRemoval1.zero_Y0
                    section.data(5).logicalSrcIdx = 163;
                    section.data(5).dtTransOffset = 4;

                    ;% Lab5_template2023_P.BiasRemoval1.Constant_Value
                    section.data(6).logicalSrcIdx = 164;
                    section.data(6).dtTransOffset = 5;

                    ;% Lab5_template2023_P.BiasRemoval1.Vbiased_Y0
                    section.data(7).logicalSrcIdx = 165;
                    section.data(7).dtTransOffset = 6;

                    ;% Lab5_template2023_P.BiasRemoval1.Vunbiased_Y0
                    section.data(8).logicalSrcIdx = 166;
                    section.data(8).dtTransOffset = 7;

                    ;% Lab5_template2023_P.BiasRemoval1.Stepstart_time_Y0
                    section.data(9).logicalSrcIdx = 167;
                    section.data(9).dtTransOffset = 8;

                    ;% Lab5_template2023_P.BiasRemoval1.Stepstart_time_YFinal
                    section.data(10).logicalSrcIdx = 168;
                    section.data(10).dtTransOffset = 9;

                    ;% Lab5_template2023_P.BiasRemoval1.Stepend_time_Y0
                    section.data(11).logicalSrcIdx = 169;
                    section.data(11).dtTransOffset = 10;

                    ;% Lab5_template2023_P.BiasRemoval1.Stepend_time_YFinal
                    section.data(12).logicalSrcIdx = 170;
                    section.data(12).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            paramMap.sections(9) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% Lab5_template2023_P.BiasRemoval.x_avg_n_Y0
                    section.data(1).logicalSrcIdx = 171;
                    section.data(1).dtTransOffset = 0;

                    ;% Lab5_template2023_P.BiasRemoval.unity_Value
                    section.data(2).logicalSrcIdx = 172;
                    section.data(2).dtTransOffset = 1;

                    ;% Lab5_template2023_P.BiasRemoval.UnitDelay_InitialCondition
                    section.data(3).logicalSrcIdx = 173;
                    section.data(3).dtTransOffset = 2;

                    ;% Lab5_template2023_P.BiasRemoval.Sumk1n1xk_InitialCondition
                    section.data(4).logicalSrcIdx = 174;
                    section.data(4).dtTransOffset = 3;

                    ;% Lab5_template2023_P.BiasRemoval.zero_Y0
                    section.data(5).logicalSrcIdx = 175;
                    section.data(5).dtTransOffset = 4;

                    ;% Lab5_template2023_P.BiasRemoval.Constant_Value
                    section.data(6).logicalSrcIdx = 176;
                    section.data(6).dtTransOffset = 5;

                    ;% Lab5_template2023_P.BiasRemoval.Vbiased_Y0
                    section.data(7).logicalSrcIdx = 177;
                    section.data(7).dtTransOffset = 6;

                    ;% Lab5_template2023_P.BiasRemoval.Vunbiased_Y0
                    section.data(8).logicalSrcIdx = 178;
                    section.data(8).dtTransOffset = 7;

                    ;% Lab5_template2023_P.BiasRemoval.Stepstart_time_Y0
                    section.data(9).logicalSrcIdx = 179;
                    section.data(9).dtTransOffset = 8;

                    ;% Lab5_template2023_P.BiasRemoval.Stepstart_time_YFinal
                    section.data(10).logicalSrcIdx = 180;
                    section.data(10).dtTransOffset = 9;

                    ;% Lab5_template2023_P.BiasRemoval.Stepend_time_Y0
                    section.data(11).logicalSrcIdx = 181;
                    section.data(11).dtTransOffset = 10;

                    ;% Lab5_template2023_P.BiasRemoval.Stepend_time_YFinal
                    section.data(12).logicalSrcIdx = 182;
                    section.data(12).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            paramMap.sections(10) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (Lab5_template2023_B)
        ;%
            section.nData     = 20;
            section.data(20)  = dumData; %prealloc

                    ;% Lab5_template2023_B.XGainNV
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Lab5_template2023_B.YGainNV
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Lab5_template2023_B.x0
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% Lab5_template2023_B.Integrator1
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% Lab5_template2023_B.Product
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% Lab5_template2023_B.Product1
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% Lab5_template2023_B.x0_i
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% Lab5_template2023_B.Integrator1_f
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% Lab5_template2023_B.Product_e
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% Lab5_template2023_B.Product1_p
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% Lab5_template2023_B.EncoderGain
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% Lab5_template2023_B.Sum2
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 12;

                    ;% Lab5_template2023_B.FilterCoefficient
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 14;

                    ;% Lab5_template2023_B.current
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 16;

                    ;% Lab5_template2023_B.uAmpGain
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 18;

                    ;% Lab5_template2023_B.uSenseGain
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 20;

                    ;% Lab5_template2023_B.RateTransition
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 22;

                    ;% Lab5_template2023_B.x
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 24;

                    ;% Lab5_template2023_B.F0
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 26;

                    ;% Lab5_template2023_B.x_i
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 28;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% Lab5_template2023_B.BiasRemoval1.Switch
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

                    ;% Lab5_template2023_B.BiasRemoval1.VVavg
                    section.data(2).logicalSrcIdx = 21;
                    section.data(2).dtTransOffset = 1;

                    ;% Lab5_template2023_B.BiasRemoval1.Vin
                    section.data(3).logicalSrcIdx = 22;
                    section.data(3).dtTransOffset = 2;

                    ;% Lab5_template2023_B.BiasRemoval1.Constant
                    section.data(4).logicalSrcIdx = 23;
                    section.data(4).dtTransOffset = 3;

                    ;% Lab5_template2023_B.BiasRemoval1.Count
                    section.data(5).logicalSrcIdx = 24;
                    section.data(5).dtTransOffset = 4;

                    ;% Lab5_template2023_B.BiasRemoval1.Sum
                    section.data(6).logicalSrcIdx = 25;
                    section.data(6).dtTransOffset = 5;

                    ;% Lab5_template2023_B.BiasRemoval1.div
                    section.data(7).logicalSrcIdx = 26;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% Lab5_template2023_B.BiasRemoval.Switch
                    section.data(1).logicalSrcIdx = 28;
                    section.data(1).dtTransOffset = 0;

                    ;% Lab5_template2023_B.BiasRemoval.VVavg
                    section.data(2).logicalSrcIdx = 29;
                    section.data(2).dtTransOffset = 1;

                    ;% Lab5_template2023_B.BiasRemoval.Vin
                    section.data(3).logicalSrcIdx = 30;
                    section.data(3).dtTransOffset = 2;

                    ;% Lab5_template2023_B.BiasRemoval.Constant
                    section.data(4).logicalSrcIdx = 31;
                    section.data(4).dtTransOffset = 3;

                    ;% Lab5_template2023_B.BiasRemoval.Count
                    section.data(5).logicalSrcIdx = 32;
                    section.data(5).dtTransOffset = 4;

                    ;% Lab5_template2023_B.BiasRemoval.Sum
                    section.data(6).logicalSrcIdx = 33;
                    section.data(6).dtTransOffset = 5;

                    ;% Lab5_template2023_B.BiasRemoval.div
                    section.data(7).logicalSrcIdx = 34;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 13;
        sectIdxOffset = 3;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (Lab5_template2023_DW)
        ;%
            section.nData     = 17;
            section.data(17)  = dumData; %prealloc

                    ;% Lab5_template2023_DW.HILInitialize_AOVoltages
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Lab5_template2023_DW.HILInitialize_AIMinimums
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Lab5_template2023_DW.HILInitialize_AIMaximums
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 9;

                    ;% Lab5_template2023_DW.HILInitialize_AOMinimums
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 17;

                    ;% Lab5_template2023_DW.HILInitialize_AOMaximums
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 25;

                    ;% Lab5_template2023_DW.HILInitialize_AOVoltages_a
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 33;

                    ;% Lab5_template2023_DW.HILInitialize_FilterFrequency
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 41;

                    ;% Lab5_template2023_DW.HILInitialize_POSortedFreqs
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 49;

                    ;% Lab5_template2023_DW.HILInitialize_POValues
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 57;

                    ;% Lab5_template2023_DW.HILReadAnalog_Buffer
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 65;

                    ;% Lab5_template2023_DW.TimeStampA
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 67;

                    ;% Lab5_template2023_DW.LastUAtTimeA
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 68;

                    ;% Lab5_template2023_DW.TimeStampB
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 70;

                    ;% Lab5_template2023_DW.LastUAtTimeB
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 71;

                    ;% Lab5_template2023_DW.XYSuperimposed_XBuffer
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 73;

                    ;% Lab5_template2023_DW.XYSuperimposed_YBuffer
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 20073;

                    ;% Lab5_template2023_DW.RateTransition_Buffer
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 40073;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Lab5_template2023_DW.HILInitialize_Card
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

                    ;% Lab5_template2023_DW.HILInitialize_Card_k
                    section.data(2).logicalSrcIdx = 18;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% Lab5_template2023_DW.HILReadAnalog_PWORK
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

                    ;% Lab5_template2023_DW.HILReadEncoder_PWORK
                    section.data(2).logicalSrcIdx = 20;
                    section.data(2).dtTransOffset = 1;

                    ;% Lab5_template2023_DW.HILWriteAnalog_PWORK
                    section.data(3).logicalSrcIdx = 21;
                    section.data(3).dtTransOffset = 2;

                    ;% Lab5_template2023_DW.MotorCurrentCommands_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 22;
                    section.data(4).dtTransOffset = 3;

                    ;% Lab5_template2023_DW.HILReadAnalog_PWORK_a
                    section.data(5).logicalSrcIdx = 23;
                    section.data(5).dtTransOffset = 4;

                    ;% Lab5_template2023_DW.ActualMotorCurrents_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 24;
                    section.data(6).dtTransOffset = 5;

                    ;% Lab5_template2023_DW.ForcesinEndEffectorFrame_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 25;
                    section.data(7).dtTransOffset = 6;

                    ;% Lab5_template2023_DW.F_PWORK.LoggedData
                    section.data(8).logicalSrcIdx = 26;
                    section.data(8).dtTransOffset = 7;

                    ;% Lab5_template2023_DW.XYErrors_PWORK.LoggedData
                    section.data(9).logicalSrcIdx = 27;
                    section.data(9).dtTransOffset = 8;

                    ;% Lab5_template2023_DW.ToWorkspace1_PWORK.LoggedData
                    section.data(10).logicalSrcIdx = 28;
                    section.data(10).dtTransOffset = 9;

                    ;% Lab5_template2023_DW.ToWorkspace2_PWORK.LoggedData
                    section.data(11).logicalSrcIdx = 29;
                    section.data(11).dtTransOffset = 10;

                    ;% Lab5_template2023_DW.Phi_PWORK.LoggedData
                    section.data(12).logicalSrcIdx = 30;
                    section.data(12).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% Lab5_template2023_DW.HILInitialize_ClockModes
                    section.data(1).logicalSrcIdx = 31;
                    section.data(1).dtTransOffset = 0;

                    ;% Lab5_template2023_DW.HILInitialize_QuadratureModes
                    section.data(2).logicalSrcIdx = 32;
                    section.data(2).dtTransOffset = 3;

                    ;% Lab5_template2023_DW.HILInitialize_InitialEICounts
                    section.data(3).logicalSrcIdx = 33;
                    section.data(3).dtTransOffset = 11;

                    ;% Lab5_template2023_DW.HILInitialize_POModeValues
                    section.data(4).logicalSrcIdx = 34;
                    section.data(4).dtTransOffset = 19;

                    ;% Lab5_template2023_DW.HILInitialize_POAlignValues
                    section.data(5).logicalSrcIdx = 35;
                    section.data(5).dtTransOffset = 27;

                    ;% Lab5_template2023_DW.HILInitialize_POPolarityVals
                    section.data(6).logicalSrcIdx = 36;
                    section.data(6).dtTransOffset = 35;

                    ;% Lab5_template2023_DW.HILReadEncoder_Buffer
                    section.data(7).logicalSrcIdx = 37;
                    section.data(7).dtTransOffset = 43;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Lab5_template2023_DW.HILInitialize_POSortedChans
                    section.data(1).logicalSrcIdx = 38;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Lab5_template2023_DW.Integrator1_IWORK
                    section.data(1).logicalSrcIdx = 39;
                    section.data(1).dtTransOffset = 0;

                    ;% Lab5_template2023_DW.Integrator1_IWORK_f
                    section.data(2).logicalSrcIdx = 40;
                    section.data(2).dtTransOffset = 1;

                    ;% Lab5_template2023_DW.XYSuperimposed_IWORK
                    section.data(3).logicalSrcIdx = 41;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Lab5_template2023_DW.XYSuperimposed_IsFull
                    section.data(1).logicalSrcIdx = 42;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Lab5_template2023_DW.BiasRemoval1.UnitDelay_DSTATE
                    section.data(1).logicalSrcIdx = 43;
                    section.data(1).dtTransOffset = 0;

                    ;% Lab5_template2023_DW.BiasRemoval1.Sumk1n1xk_DSTATE
                    section.data(2).logicalSrcIdx = 44;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% Lab5_template2023_DW.BiasRemoval1.SwitchCase_ActiveSubsystem
                    section.data(1).logicalSrcIdx = 45;
                    section.data(1).dtTransOffset = 0;

                    ;% Lab5_template2023_DW.BiasRemoval1.SwitchCaseActionSubsystem2_Subs
                    section.data(2).logicalSrcIdx = 46;
                    section.data(2).dtTransOffset = 1;

                    ;% Lab5_template2023_DW.BiasRemoval1.SwitchCaseActionSubsystem1_Subs
                    section.data(3).logicalSrcIdx = 47;
                    section.data(3).dtTransOffset = 2;

                    ;% Lab5_template2023_DW.BiasRemoval1.SwitchCaseActionSubsystem_Subsy
                    section.data(4).logicalSrcIdx = 48;
                    section.data(4).dtTransOffset = 3;

                    ;% Lab5_template2023_DW.BiasRemoval1.EnabledMovingAverage_SubsysRanB
                    section.data(5).logicalSrcIdx = 49;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Lab5_template2023_DW.BiasRemoval1.EnabledMovingAverage_MODE
                    section.data(1).logicalSrcIdx = 50;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Lab5_template2023_DW.BiasRemoval.UnitDelay_DSTATE
                    section.data(1).logicalSrcIdx = 51;
                    section.data(1).dtTransOffset = 0;

                    ;% Lab5_template2023_DW.BiasRemoval.Sumk1n1xk_DSTATE
                    section.data(2).logicalSrcIdx = 52;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% Lab5_template2023_DW.BiasRemoval.SwitchCase_ActiveSubsystem
                    section.data(1).logicalSrcIdx = 53;
                    section.data(1).dtTransOffset = 0;

                    ;% Lab5_template2023_DW.BiasRemoval.SwitchCaseActionSubsystem2_Subs
                    section.data(2).logicalSrcIdx = 54;
                    section.data(2).dtTransOffset = 1;

                    ;% Lab5_template2023_DW.BiasRemoval.SwitchCaseActionSubsystem1_Subs
                    section.data(3).logicalSrcIdx = 55;
                    section.data(3).dtTransOffset = 2;

                    ;% Lab5_template2023_DW.BiasRemoval.SwitchCaseActionSubsystem_Subsy
                    section.data(4).logicalSrcIdx = 56;
                    section.data(4).dtTransOffset = 3;

                    ;% Lab5_template2023_DW.BiasRemoval.EnabledMovingAverage_SubsysRanB
                    section.data(5).logicalSrcIdx = 57;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Lab5_template2023_DW.BiasRemoval.EnabledMovingAverage_MODE
                    section.data(1).logicalSrcIdx = 58;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(13) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 2810172923;
    targMap.checksum1 = 3707460084;
    targMap.checksum2 = 2064570272;
    targMap.checksum3 = 1223995506;

