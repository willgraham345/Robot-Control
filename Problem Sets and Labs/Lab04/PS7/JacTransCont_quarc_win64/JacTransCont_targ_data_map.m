    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 8;
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
        ;% Auto data (JacTransCont_P)
        ;%
            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% JacTransCont_P.PIDController_D
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% JacTransCont_P.PIDController_InitialConditionF
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% JacTransCont_P.PIDController_N
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% JacTransCont_P.PIDController_P
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% JacTransCont_P.XYSuperimposed_maximum_x
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% JacTransCont_P.XYSuperimposed_maximum_y
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% JacTransCont_P.XYSuperimposed_minimum_x
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% JacTransCont_P.XYSuperimposed_minimum_y
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% JacTransCont_P.XYSuperimposed_update_rate
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% JacTransCont_P.HILReadEncoder_channels
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

                    ;% JacTransCont_P.HILWriteAnalog_channels
                    section.data(2).logicalSrcIdx = 10;
                    section.data(2).dtTransOffset = 2;

                    ;% JacTransCont_P.HILReadAnalog_channels
                    section.data(3).logicalSrcIdx = 11;
                    section.data(3).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 24;
            section.data(24)  = dumData; %prealloc

                    ;% JacTransCont_P.HILInitialize_OOTerminate
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% JacTransCont_P.HILInitialize_OOExit
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 1;

                    ;% JacTransCont_P.HILInitialize_OOStart
                    section.data(3).logicalSrcIdx = 14;
                    section.data(3).dtTransOffset = 2;

                    ;% JacTransCont_P.HILInitialize_OOEnter
                    section.data(4).logicalSrcIdx = 15;
                    section.data(4).dtTransOffset = 3;

                    ;% JacTransCont_P.HILInitialize_AOFinal
                    section.data(5).logicalSrcIdx = 16;
                    section.data(5).dtTransOffset = 4;

                    ;% JacTransCont_P.HILInitialize_POFinal
                    section.data(6).logicalSrcIdx = 17;
                    section.data(6).dtTransOffset = 5;

                    ;% JacTransCont_P.HILInitialize_AIHigh
                    section.data(7).logicalSrcIdx = 18;
                    section.data(7).dtTransOffset = 6;

                    ;% JacTransCont_P.HILInitialize_AILow
                    section.data(8).logicalSrcIdx = 19;
                    section.data(8).dtTransOffset = 7;

                    ;% JacTransCont_P.HILInitialize_AOHigh
                    section.data(9).logicalSrcIdx = 20;
                    section.data(9).dtTransOffset = 8;

                    ;% JacTransCont_P.HILInitialize_AOLow
                    section.data(10).logicalSrcIdx = 21;
                    section.data(10).dtTransOffset = 9;

                    ;% JacTransCont_P.HILInitialize_AOInitial
                    section.data(11).logicalSrcIdx = 22;
                    section.data(11).dtTransOffset = 10;

                    ;% JacTransCont_P.HILInitialize_AOWatchdog
                    section.data(12).logicalSrcIdx = 23;
                    section.data(12).dtTransOffset = 11;

                    ;% JacTransCont_P.HILInitialize_POFrequency
                    section.data(13).logicalSrcIdx = 24;
                    section.data(13).dtTransOffset = 12;

                    ;% JacTransCont_P.HILInitialize_POLeading
                    section.data(14).logicalSrcIdx = 25;
                    section.data(14).dtTransOffset = 13;

                    ;% JacTransCont_P.HILInitialize_POTrailing
                    section.data(15).logicalSrcIdx = 26;
                    section.data(15).dtTransOffset = 14;

                    ;% JacTransCont_P.HILInitialize_POInitial
                    section.data(16).logicalSrcIdx = 27;
                    section.data(16).dtTransOffset = 15;

                    ;% JacTransCont_P.HILInitialize_POWatchdog
                    section.data(17).logicalSrcIdx = 28;
                    section.data(17).dtTransOffset = 16;

                    ;% JacTransCont_P.HomePosition_Value
                    section.data(18).logicalSrcIdx = 29;
                    section.data(18).dtTransOffset = 17;

                    ;% JacTransCont_P.EncoderGain_Gain
                    section.data(19).logicalSrcIdx = 30;
                    section.data(19).dtTransOffset = 19;

                    ;% JacTransCont_P.Speed_Value
                    section.data(20).logicalSrcIdx = 31;
                    section.data(20).dtTransOffset = 21;

                    ;% JacTransCont_P.AmpBiasTuneforeachampchannelifn
                    section.data(21).logicalSrcIdx = 32;
                    section.data(21).dtTransOffset = 22;

                    ;% JacTransCont_P.uAmpGain_Gain
                    section.data(22).logicalSrcIdx = 33;
                    section.data(22).dtTransOffset = 24;

                    ;% JacTransCont_P.uSenseGain_Gain
                    section.data(23).logicalSrcIdx = 34;
                    section.data(23).dtTransOffset = 26;

                    ;% JacTransCont_P.CurrentSenseBiasTuneforeachampc
                    section.data(24).logicalSrcIdx = 35;
                    section.data(24).dtTransOffset = 27;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% JacTransCont_P.HILInitialize_CKChannels
                    section.data(1).logicalSrcIdx = 36;
                    section.data(1).dtTransOffset = 0;

                    ;% JacTransCont_P.HILInitialize_DOWatchdog
                    section.data(2).logicalSrcIdx = 37;
                    section.data(2).dtTransOffset = 3;

                    ;% JacTransCont_P.HILInitialize_EIInitial
                    section.data(3).logicalSrcIdx = 38;
                    section.data(3).dtTransOffset = 4;

                    ;% JacTransCont_P.HILInitialize_POModes
                    section.data(4).logicalSrcIdx = 39;
                    section.data(4).dtTransOffset = 5;

                    ;% JacTransCont_P.HILInitialize_POConfiguration
                    section.data(5).logicalSrcIdx = 40;
                    section.data(5).dtTransOffset = 6;

                    ;% JacTransCont_P.HILInitialize_POAlignment
                    section.data(6).logicalSrcIdx = 41;
                    section.data(6).dtTransOffset = 7;

                    ;% JacTransCont_P.HILInitialize_POPolarity
                    section.data(7).logicalSrcIdx = 42;
                    section.data(7).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% JacTransCont_P.HILInitialize_AIChannels
                    section.data(1).logicalSrcIdx = 43;
                    section.data(1).dtTransOffset = 0;

                    ;% JacTransCont_P.HILInitialize_AOChannels
                    section.data(2).logicalSrcIdx = 44;
                    section.data(2).dtTransOffset = 8;

                    ;% JacTransCont_P.HILInitialize_EIChannels
                    section.data(3).logicalSrcIdx = 45;
                    section.data(3).dtTransOffset = 16;

                    ;% JacTransCont_P.HILInitialize_EIQuadrature
                    section.data(4).logicalSrcIdx = 46;
                    section.data(4).dtTransOffset = 24;

                    ;% JacTransCont_P.HILInitialize_POChannels
                    section.data(5).logicalSrcIdx = 47;
                    section.data(5).dtTransOffset = 25;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 38;
            section.data(38)  = dumData; %prealloc

                    ;% JacTransCont_P.HILInitialize_Active
                    section.data(1).logicalSrcIdx = 48;
                    section.data(1).dtTransOffset = 0;

                    ;% JacTransCont_P.HILInitialize_AOTerminate
                    section.data(2).logicalSrcIdx = 49;
                    section.data(2).dtTransOffset = 1;

                    ;% JacTransCont_P.HILInitialize_AOExit
                    section.data(3).logicalSrcIdx = 50;
                    section.data(3).dtTransOffset = 2;

                    ;% JacTransCont_P.HILInitialize_DOTerminate
                    section.data(4).logicalSrcIdx = 51;
                    section.data(4).dtTransOffset = 3;

                    ;% JacTransCont_P.HILInitialize_DOExit
                    section.data(5).logicalSrcIdx = 52;
                    section.data(5).dtTransOffset = 4;

                    ;% JacTransCont_P.HILInitialize_POTerminate
                    section.data(6).logicalSrcIdx = 53;
                    section.data(6).dtTransOffset = 5;

                    ;% JacTransCont_P.HILInitialize_POExit
                    section.data(7).logicalSrcIdx = 54;
                    section.data(7).dtTransOffset = 6;

                    ;% JacTransCont_P.HILInitialize_CKPStart
                    section.data(8).logicalSrcIdx = 55;
                    section.data(8).dtTransOffset = 7;

                    ;% JacTransCont_P.HILInitialize_CKPEnter
                    section.data(9).logicalSrcIdx = 56;
                    section.data(9).dtTransOffset = 8;

                    ;% JacTransCont_P.HILInitialize_CKStart
                    section.data(10).logicalSrcIdx = 57;
                    section.data(10).dtTransOffset = 9;

                    ;% JacTransCont_P.HILInitialize_CKEnter
                    section.data(11).logicalSrcIdx = 58;
                    section.data(11).dtTransOffset = 10;

                    ;% JacTransCont_P.HILInitialize_AIPStart
                    section.data(12).logicalSrcIdx = 59;
                    section.data(12).dtTransOffset = 11;

                    ;% JacTransCont_P.HILInitialize_AIPEnter
                    section.data(13).logicalSrcIdx = 60;
                    section.data(13).dtTransOffset = 12;

                    ;% JacTransCont_P.HILInitialize_AOPStart
                    section.data(14).logicalSrcIdx = 61;
                    section.data(14).dtTransOffset = 13;

                    ;% JacTransCont_P.HILInitialize_AOPEnter
                    section.data(15).logicalSrcIdx = 62;
                    section.data(15).dtTransOffset = 14;

                    ;% JacTransCont_P.HILInitialize_AOStart
                    section.data(16).logicalSrcIdx = 63;
                    section.data(16).dtTransOffset = 15;

                    ;% JacTransCont_P.HILInitialize_AOEnter
                    section.data(17).logicalSrcIdx = 64;
                    section.data(17).dtTransOffset = 16;

                    ;% JacTransCont_P.HILInitialize_AOReset
                    section.data(18).logicalSrcIdx = 65;
                    section.data(18).dtTransOffset = 17;

                    ;% JacTransCont_P.HILInitialize_DOPStart
                    section.data(19).logicalSrcIdx = 66;
                    section.data(19).dtTransOffset = 18;

                    ;% JacTransCont_P.HILInitialize_DOPEnter
                    section.data(20).logicalSrcIdx = 67;
                    section.data(20).dtTransOffset = 19;

                    ;% JacTransCont_P.HILInitialize_DOStart
                    section.data(21).logicalSrcIdx = 68;
                    section.data(21).dtTransOffset = 20;

                    ;% JacTransCont_P.HILInitialize_DOEnter
                    section.data(22).logicalSrcIdx = 69;
                    section.data(22).dtTransOffset = 21;

                    ;% JacTransCont_P.HILInitialize_DOReset
                    section.data(23).logicalSrcIdx = 70;
                    section.data(23).dtTransOffset = 22;

                    ;% JacTransCont_P.HILInitialize_EIPStart
                    section.data(24).logicalSrcIdx = 71;
                    section.data(24).dtTransOffset = 23;

                    ;% JacTransCont_P.HILInitialize_EIPEnter
                    section.data(25).logicalSrcIdx = 72;
                    section.data(25).dtTransOffset = 24;

                    ;% JacTransCont_P.HILInitialize_EIStart
                    section.data(26).logicalSrcIdx = 73;
                    section.data(26).dtTransOffset = 25;

                    ;% JacTransCont_P.HILInitialize_EIEnter
                    section.data(27).logicalSrcIdx = 74;
                    section.data(27).dtTransOffset = 26;

                    ;% JacTransCont_P.HILInitialize_POPStart
                    section.data(28).logicalSrcIdx = 75;
                    section.data(28).dtTransOffset = 27;

                    ;% JacTransCont_P.HILInitialize_POPEnter
                    section.data(29).logicalSrcIdx = 76;
                    section.data(29).dtTransOffset = 28;

                    ;% JacTransCont_P.HILInitialize_POStart
                    section.data(30).logicalSrcIdx = 77;
                    section.data(30).dtTransOffset = 29;

                    ;% JacTransCont_P.HILInitialize_POEnter
                    section.data(31).logicalSrcIdx = 78;
                    section.data(31).dtTransOffset = 30;

                    ;% JacTransCont_P.HILInitialize_POReset
                    section.data(32).logicalSrcIdx = 79;
                    section.data(32).dtTransOffset = 31;

                    ;% JacTransCont_P.HILInitialize_OOReset
                    section.data(33).logicalSrcIdx = 80;
                    section.data(33).dtTransOffset = 32;

                    ;% JacTransCont_P.HILInitialize_DOFinal
                    section.data(34).logicalSrcIdx = 81;
                    section.data(34).dtTransOffset = 33;

                    ;% JacTransCont_P.HILInitialize_DOInitial
                    section.data(35).logicalSrcIdx = 82;
                    section.data(35).dtTransOffset = 34;

                    ;% JacTransCont_P.HILReadEncoder_Active
                    section.data(36).logicalSrcIdx = 83;
                    section.data(36).dtTransOffset = 35;

                    ;% JacTransCont_P.HILWriteAnalog_Active
                    section.data(37).logicalSrcIdx = 84;
                    section.data(37).dtTransOffset = 36;

                    ;% JacTransCont_P.HILReadAnalog_Active
                    section.data(38).logicalSrcIdx = 85;
                    section.data(38).dtTransOffset = 37;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% JacTransCont_P.XYSuperimposed_Mode
                    section.data(1).logicalSrcIdx = 86;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
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
        nTotSects     = 1;
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
        ;% Auto data (JacTransCont_B)
        ;%
            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% JacTransCont_B.EncoderGain
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% JacTransCont_B.Speed
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% JacTransCont_B.Sum
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 3;

                    ;% JacTransCont_B.FilterCoefficient
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% JacTransCont_B.uAmpGain
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 7;

                    ;% JacTransCont_B.CurrentSenseBiasTuneforeachampc
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 9;

                    ;% JacTransCont_B.RateTransition
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 11;

                    ;% JacTransCont_B.x
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 13;

                    ;% JacTransCont_B.tau
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 15;

                    ;% JacTransCont_B.x_b
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 17;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
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
        nTotSects     = 7;
        sectIdxOffset = 1;

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
        ;% Auto data (JacTransCont_DW)
        ;%
            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% JacTransCont_DW.HILInitialize_AIMinimums
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% JacTransCont_DW.HILInitialize_AIMaximums
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 8;

                    ;% JacTransCont_DW.HILInitialize_AOMinimums
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 16;

                    ;% JacTransCont_DW.HILInitialize_AOMaximums
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 24;

                    ;% JacTransCont_DW.HILInitialize_AOVoltages
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 32;

                    ;% JacTransCont_DW.HILInitialize_FilterFrequency
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 40;

                    ;% JacTransCont_DW.HILInitialize_POSortedFreqs
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 48;

                    ;% JacTransCont_DW.HILInitialize_POValues
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 56;

                    ;% JacTransCont_DW.XYSuperimposed_XBuffer
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 64;

                    ;% JacTransCont_DW.XYSuperimposed_YBuffer
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 20064;

                    ;% JacTransCont_DW.RateTransition_Buffer
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 40064;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% JacTransCont_DW.HILInitialize_Card
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% JacTransCont_DW.HILReadEncoder_PWORK
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% JacTransCont_DW.HILWriteAnalog_PWORK
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 1;

                    ;% JacTransCont_DW.MotorCurrentCommands_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 14;
                    section.data(3).dtTransOffset = 2;

                    ;% JacTransCont_DW.HILReadAnalog_PWORK
                    section.data(4).logicalSrcIdx = 15;
                    section.data(4).dtTransOffset = 3;

                    ;% JacTransCont_DW.ActualMotorCurrents_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 16;
                    section.data(5).dtTransOffset = 4;

                    ;% JacTransCont_DW.ToWorkspace5_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 17;
                    section.data(6).dtTransOffset = 5;

                    ;% JacTransCont_DW.ToWorkspace6_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 18;
                    section.data(7).dtTransOffset = 6;

                    ;% JacTransCont_DW.ToWorkspace1_PWORK.LoggedData
                    section.data(8).logicalSrcIdx = 19;
                    section.data(8).dtTransOffset = 7;

                    ;% JacTransCont_DW.ToWorkspace2_PWORK.LoggedData
                    section.data(9).logicalSrcIdx = 20;
                    section.data(9).dtTransOffset = 8;

                    ;% JacTransCont_DW.Phi_PWORK.LoggedData
                    section.data(10).logicalSrcIdx = 21;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% JacTransCont_DW.HILInitialize_ClockModes
                    section.data(1).logicalSrcIdx = 22;
                    section.data(1).dtTransOffset = 0;

                    ;% JacTransCont_DW.HILInitialize_QuadratureModes
                    section.data(2).logicalSrcIdx = 23;
                    section.data(2).dtTransOffset = 3;

                    ;% JacTransCont_DW.HILInitialize_InitialEICounts
                    section.data(3).logicalSrcIdx = 24;
                    section.data(3).dtTransOffset = 11;

                    ;% JacTransCont_DW.HILInitialize_POModeValues
                    section.data(4).logicalSrcIdx = 25;
                    section.data(4).dtTransOffset = 19;

                    ;% JacTransCont_DW.HILInitialize_POAlignValues
                    section.data(5).logicalSrcIdx = 26;
                    section.data(5).dtTransOffset = 27;

                    ;% JacTransCont_DW.HILInitialize_POPolarityVals
                    section.data(6).logicalSrcIdx = 27;
                    section.data(6).dtTransOffset = 35;

                    ;% JacTransCont_DW.HILReadEncoder_Buffer
                    section.data(7).logicalSrcIdx = 28;
                    section.data(7).dtTransOffset = 43;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% JacTransCont_DW.HILInitialize_POSortedChans
                    section.data(1).logicalSrcIdx = 29;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% JacTransCont_DW.XYSuperimposed_IWORK
                    section.data(1).logicalSrcIdx = 30;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% JacTransCont_DW.XYSuperimposed_IsFull
                    section.data(1).logicalSrcIdx = 31;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
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


    targMap.checksum0 = 1549397743;
    targMap.checksum1 = 1249630855;
    targMap.checksum2 = 1753096625;
    targMap.checksum3 = 2111269722;
