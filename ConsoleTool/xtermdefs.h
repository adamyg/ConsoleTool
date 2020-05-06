#pragma once
#ifndef XTERMDEFS_H_INCLUDED
#define XTERMDEFS_H_INCLUDED

//
//  XTERM Standard colors
//

const struct XTERM_COLOR {
	const char *name;
	COLORREF rbg;

} XTERM_COLORS[] = {
	/*0  */  {  "Black (SYSTEM)   ", RGB(0,0,0)         },
	/*1  */  {  "Maroon (SYSTEM)  ", RGB(128,0,0)       },
	/*2  */  {  "Green (SYSTEM)   ", RGB(0,128,0)       },
	/*3  */  {  "Olive (SYSTEM)   ", RGB(128,128,0)     },
	/*4  */  {  "Navy (SYSTEM)    ", RGB(0,0,128)       },
	/*5  */  {  "Purple (SYSTEM)  ", RGB(128,0,128)     },
	/*6  */  {  "Teal (SYSTEM)    ", RGB(0,128,128)     },
	/*7  */  {  "Silver (SYSTEM)  ", RGB(192,192,192)   },
	/*8  */  {  "Grey (SYSTEM)    ", RGB(128,128,128)   },
	/*9  */  {  "Red (SYSTEM)     ", RGB(255,0,0)       },
	/*10 */  {  "Lime (SYSTEM)    ", RGB(0,255,0)       },
	/*11 */  {  "Yellow (SYSTEM)  ", RGB(255,255,0)     },
	/*12 */  {  "Blue (SYSTEM)    ", RGB(0,0,255)       },
	/*13 */  {  "Fuchsia (SYSTEM) ", RGB(255,0,255)     },
	/*14 */  {  "Aqua (SYSTEM)    ", RGB(0,255,255)     },
	/*15 */  {  "White (SYSTEM)   ", RGB(255,255,255)   },
	/*16 */  {  "Grey0            ", RGB(0,0,0)         },
	/*17 */  {  "NavyBlue         ", RGB(0,0,95)        },
	/*18 */  {  "DarkBlue         ", RGB(0,0,135)       },
	/*19 */  {  "Blue3            ", RGB(0,0,175)       },
	/*20 */  {  "Blue3            ", RGB(0,0,215)       },
	/*21 */  {  "Blue1            ", RGB(0,0,255)       },
	/*22 */  {  "DarkGreen        ", RGB(0,95,0)        },
	/*23 */  {  "DeepSkyBlue4     ", RGB(0,95,95)       },
	/*24 */  {  "DeepSkyBlue4     ", RGB(0,95,135)      },
	/*25 */  {  "DeepSkyBlue4     ", RGB(0,95,175)      },
	/*26 */  {  "DodgerBlue3      ", RGB(0,95,215)      },
	/*27 */  {  "DodgerBlue2      ", RGB(0,95,255)      },
	/*28 */  {  "Green4           ", RGB(0,135,0)       },
	/*29 */  {  "SpringGreen4     ", RGB(0,135,95)      },
	/*30 */  {  "Turquoise4       ", RGB(0,135,135)     },
	/*31 */  {  "DeepSkyBlue3     ", RGB(0,135,175)     },
	/*32 */  {  "DeepSkyBlue3     ", RGB(0,135,215)     },
	/*33 */  {  "DodgerBlue1      ", RGB(0,135,255)     },
	/*34 */  {  "Green3           ", RGB(0,175,0)       },
	/*35 */  {  "SpringGreen3     ", RGB(0,175,95)      },
	/*36 */  {  "DarkCyan         ", RGB(0,175,135)     },
	/*37 */  {  "LightSeaGreen    ", RGB(0,175,175)     },
	/*38 */  {  "DeepSkyBlue2     ", RGB(0,175,215)     },
	/*39 */  {  "DeepSkyBlue1     ", RGB(0,175,255)     },
	/*40 */  {  "Green3           ", RGB(0,215,0)       },
	/*41 */  {  "SpringGreen3     ", RGB(0,215,95)      },
	/*42 */  {  "SpringGreen2     ", RGB(0,215,135)     },
	/*43 */  {  "Cyan3            ", RGB(0,215,175)     },
	/*44 */  {  "DarkTurquoise    ", RGB(0,215,215)     },
	/*45 */  {  "Turquoise2       ", RGB(0,215,255)     },
	/*46 */  {  "Green1           ", RGB(0,255,0)       },
	/*47 */  {  "SpringGreen2     ", RGB(0,255,95)      },
	/*48 */  {  "SpringGreen1     ", RGB(0,255,135)     },
	/*49 */  {  "MediumSpringGreen", RGB(0,255,175)     },
	/*50 */  {  "Cyan2            ", RGB(0,255,215)     },
	/*51 */  {  "Cyan1            ", RGB(0,255,255)     },
	/*52 */  {  "DarkRed          ", RGB(95,0,0)        },
	/*53 */  {  "DeepPink4        ", RGB(95,0,95)       },
	/*54 */  {  "Purple4          ", RGB(95,0,135)      },
	/*55 */  {  "Purple4          ", RGB(95,0,175)      },
	/*56 */  {  "Purple3          ", RGB(95,0,215)      },
	/*57 */  {  "BlueViolet       ", RGB(95,0,255)      },
	/*58 */  {  "Orange4          ", RGB(95,95,0)       },
	/*59 */  {  "Grey37           ", RGB(95,95,95)      },
	/*60 */  {  "MediumPurple4    ", RGB(95,95,135)     },
	/*61 */  {  "SlateBlue3       ", RGB(95,95,175)     },
	/*62 */  {  "SlateBlue3       ", RGB(95,95,215)     },
	/*63 */  {  "RoyalBlue1       ", RGB(95,95,255)     },
	/*64 */  {  "Chartreuse4      ", RGB(95,135,0)      },
	/*65 */  {  "DarkSeaGreen4    ", RGB(95,135,95)     },
	/*66 */  {  "PaleTurquoise4   ", RGB(95,135,135)    },
	/*67 */  {  "SteelBlue        ", RGB(95,135,175)    },
	/*68 */  {  "SteelBlue3       ", RGB(95,135,215)    },
	/*69 */  {  "CornflowerBlue   ", RGB(95,135,255)    },
	/*70 */  {  "Chartreuse3      ", RGB(95,175,0)      },
	/*71 */  {  "DarkSeaGreen4    ", RGB(95,175,95)     },
	/*72 */  {  "CadetBlue        ", RGB(95,175,135)    },
	/*73 */  {  "CadetBlue        ", RGB(95,175,175)    },
	/*74 */  {  "SkyBlue3         ", RGB(95,175,215)    },
	/*75 */  {  "SteelBlue1       ", RGB(95,175,255)    },
	/*76 */  {  "Chartreuse3      ", RGB(95,215,0)      },
	/*77 */  {  "PaleGreen3       ", RGB(95,215,95)     },
	/*78 */  {  "SeaGreen3        ", RGB(95,215,135)    },
	/*79 */  {  "Aquamarine3      ", RGB(95,215,175)    },
	/*80 */  {  "MediumTurquoise  ", RGB(95,215,215)    },
	/*81 */  {  "SteelBlue1       ", RGB(95,215,255)    },
	/*82 */  {  "Chartreuse2      ", RGB(95,255,0)      },
	/*83 */  {  "SeaGreen2        ", RGB(95,255,95)     },
	/*84 */  {  "SeaGreen1        ", RGB(95,255,135)    },
	/*85 */  {  "SeaGreen1        ", RGB(95,255,175)    },
	/*86 */  {  "Aquamarine1      ", RGB(95,255,215)    },
	/*87 */  {  "DarkSlateGray2   ", RGB(95,255,255)    },
	/*88 */  {  "DarkRed          ", RGB(135,0,0)       },
	/*89 */  {  "DeepPink4        ", RGB(135,0,95)      },
	/*90 */  {  "DarkMagenta      ", RGB(135,0,135)     },
	/*91 */  {  "DarkMagenta      ", RGB(135,0,175)     },
	/*92 */  {  "DarkViolet       ", RGB(135,0,215)     },
	/*93 */  {  "Purple           ", RGB(135,0,255)     },
	/*94 */  {  "Orange4          ", RGB(135,95,0)      },
	/*95 */  {  "LightPink4       ", RGB(135,95,95)     },
	/*96 */  {  "Plum4            ", RGB(135,95,135)    },
	/*97 */  {  "MediumPurple3    ", RGB(135,95,175)    },
	/*98 */  {  "MediumPurple3    ", RGB(135,95,215)    },
	/*99 */  {  "SlateBlue1       ", RGB(135,95,255)    },
	/*100*/  {  "Yellow4          ", RGB(135,135,0)     },
	/*101*/  {  "Wheat4           ", RGB(135,135,95)    },
	/*102*/  {  "Grey53           ", RGB(135,135,135)   },
	/*103*/  {  "LightSlateGrey   ", RGB(135,135,175)   },
	/*104*/  {  "MediumPurple     ", RGB(135,135,215)   },
	/*105*/  {  "LightSlateBlue   ", RGB(135,135,255)   },
	/*106*/  {  "Yellow4          ", RGB(135,175,0)     },
	/*107*/  {  "DarkOliveGreen3  ", RGB(135,175,95)    },
	/*108*/  {  "DarkSeaGreen     ", RGB(135,175,135)   },
	/*109*/  {  "LightSkyBlue3    ", RGB(135,175,175)   },
	/*110*/  {  "LightSkyBlue3    ", RGB(135,175,215)   },
	/*111*/  {  "SkyBlue2         ", RGB(135,175,255)   },
	/*112*/  {  "Chartreuse2      ", RGB(135,215,0)     },
	/*113*/  {  "DarkOliveGreen3  ", RGB(135,215,95)    },
	/*114*/  {  "PaleGreen3       ", RGB(135,215,135)   },
	/*115*/  {  "DarkSeaGreen3    ", RGB(135,215,175)   },
	/*116*/  {  "DarkSlateGray3   ", RGB(135,215,215)   },
	/*117*/  {  "SkyBlue1         ", RGB(135,215,255)   },
	/*118*/  {  "Chartreuse1      ", RGB(135,255,0)     },
	/*119*/  {  "LightGreen       ", RGB(135,255,95)    },
	/*120*/  {  "LightGreen       ", RGB(135,255,135)   },
	/*121*/  {  "PaleGreen1       ", RGB(135,255,175)   },
	/*122*/  {  "Aquamarine1      ", RGB(135,255,215)   },
	/*123*/  {  "DarkSlateGray1   ", RGB(135,255,255)   },
	/*124*/  {  "Red3             ", RGB(175,0,0)       },
	/*125*/  {  "DeepPink4        ", RGB(175,0,95)      },
	/*126*/  {  "MediumVioletRed  ", RGB(175,0,135)     },
	/*127*/  {  "Magenta3         ", RGB(175,0,175)     },
	/*128*/  {  "DarkViolet       ", RGB(175,0,215)     },
	/*129*/  {  "Purple           ", RGB(175,0,255)     },
	/*130*/  {  "DarkOrange3      ", RGB(175,95,0)      },
	/*131*/  {  "IndianRed        ", RGB(175,95,95)     },
	/*132*/  {  "HotPink3         ", RGB(175,95,135)    },
	/*133*/  {  "MediumOrchid3    ", RGB(175,95,175)    },
	/*134*/  {  "MediumOrchid     ", RGB(175,95,215)    },
	/*135*/  {  "MediumPurple2    ", RGB(175,95,255)    },
	/*136*/  {  "DarkGoldenrod    ", RGB(175,135,0)     },
	/*137*/  {  "LightSalmon3     ", RGB(175,135,95)    },
	/*138*/  {  "RosyBrown        ", RGB(175,135,135)   },
	/*139*/  {  "Grey63           ", RGB(175,135,175)   },
	/*140*/  {  "MediumPurple2    ", RGB(175,135,215)   },
	/*141*/  {  "MediumPurple1    ", RGB(175,135,255)   },
	/*142*/  {  "Gold3            ", RGB(175,175,0)     },
	/*143*/  {  "DarkKhaki        ", RGB(175,175,95)    },
	/*144*/  {  "NavajoWhite3     ", RGB(175,175,135)   },
	/*145*/  {  "Grey69           ", RGB(175,175,175)   },
	/*146*/  {  "LightSteelBlue3  ", RGB(175,175,215)   },
	/*147*/  {  "LightSteelBlue   ", RGB(175,175,255)   },
	/*148*/  {  "Yellow3          ", RGB(175,215,0)     },
	/*149*/  {  "DarkOliveGreen3  ", RGB(175,215,95)    },
	/*150*/  {  "DarkSeaGreen3    ", RGB(175,215,135)   },
	/*151*/  {  "DarkSeaGreen2    ", RGB(175,215,175)   },
	/*152*/  {  "LightCyan3       ", RGB(175,215,215)   },
	/*153*/  {  "LightSkyBlue1    ", RGB(175,215,255)   },
	/*154*/  {  "GreenYellow      ", RGB(175,255,0)     },
	/*155*/  {  "DarkOliveGreen2  ", RGB(175,255,95)    },
	/*156*/  {  "PaleGreen1       ", RGB(175,255,135)   },
	/*157*/  {  "DarkSeaGreen2    ", RGB(175,255,175)   },
	/*158*/  {  "DarkSeaGreen1    ", RGB(175,255,215)   },
	/*159*/  {  "PaleTurquoise1   ", RGB(175,255,255)   },
	/*160*/  {  "Red3             ", RGB(215,0,0)       },
	/*161*/  {  "DeepPink3        ", RGB(215,0,95)      },
	/*162*/  {  "DeepPink3        ", RGB(215,0,135)     },
	/*163*/  {  "Magenta3         ", RGB(215,0,175)     },
	/*164*/  {  "Magenta3         ", RGB(215,0,215)     },
	/*165*/  {  "Magenta2         ", RGB(215,0,255)     },
	/*166*/  {  "DarkOrange3      ", RGB(215,95,0)      },
	/*167*/  {  "IndianRed        ", RGB(215,95,95)     },
	/*168*/  {  "HotPink3         ", RGB(215,95,135)    },
	/*169*/  {  "HotPink2         ", RGB(215,95,175)    },
	/*170*/  {  "Orchid           ", RGB(215,95,215)    },
	/*171*/  {  "MediumOrchid1    ", RGB(215,95,255)    },
	/*172*/  {  "Orange3          ", RGB(215,135,0)     },
	/*173*/  {  "LightSalmon3     ", RGB(215,135,95)    },
	/*174*/  {  "LightPink3       ", RGB(215,135,135)   },
	/*175*/  {  "Pink3            ", RGB(215,135,175)   },
	/*176*/  {  "Plum3            ", RGB(215,135,215)   },
	/*177*/  {  "Violet           ", RGB(215,135,255)   },
	/*178*/  {  "Gold3            ", RGB(215,175,0)     },
	/*179*/  {  "LightGoldenrod3  ", RGB(215,175,95)    },
	/*180*/  {  "Tan              ", RGB(215,175,135)   },
	/*181*/  {  "MistyRose3       ", RGB(215,175,175)   },
	/*182*/  {  "Thistle3         ", RGB(215,175,215)   },
	/*183*/  {  "Plum2            ", RGB(215,175,255)   },
	/*184*/  {  "Yellow3          ", RGB(215,215,0)     },
	/*185*/  {  "Khaki3           ", RGB(215,215,95)    },
	/*186*/  {  "LightGoldenrod2  ", RGB(215,215,135)   },
	/*187*/  {  "LightYellow3     ", RGB(215,215,175)   },
	/*188*/  {  "Grey84           ", RGB(215,215,215)   },
	/*189*/  {  "LightSteelBlue1  ", RGB(215,215,255)   },
	/*190*/  {  "Yellow2          ", RGB(215,255,0)     },
	/*191*/  {  "DarkOliveGreen1  ", RGB(215,255,95)    },
	/*192*/  {  "DarkOliveGreen1  ", RGB(215,255,135)   },
	/*193*/  {  "DarkSeaGreen1    ", RGB(215,255,175)   },
	/*194*/  {  "Honeydew2        ", RGB(215,255,215)   },
	/*195*/  {  "LightCyan1       ", RGB(215,255,255)   },
	/*196*/  {  "Red1             ", RGB(255,0,0)       },
	/*197*/  {  "DeepPink2        ", RGB(255,0,95)      },
	/*198*/  {  "DeepPink1        ", RGB(255,0,135)     },
	/*199*/  {  "DeepPink1        ", RGB(255,0,175)     },
	/*200*/  {  "Magenta2         ", RGB(255,0,215)     },
	/*201*/  {  "Magenta1         ", RGB(255,0,255)     },
	/*202*/  {  "OrangeRed1       ", RGB(255,95,0)      },
	/*203*/  {  "IndianRed1       ", RGB(255,95,95)     },
	/*204*/  {  "IndianRed1       ", RGB(255,95,135)    },
	/*205*/  {  "HotPink          ", RGB(255,95,175)    },
	/*206*/  {  "HotPink          ", RGB(255,95,215)    },
	/*207*/  {  "MediumOrchid1    ", RGB(255,95,255)    },
	/*208*/  {  "DarkOrange       ", RGB(255,135,0)     },
	/*209*/  {  "Salmon1          ", RGB(255,135,95)    },
	/*210*/  {  "LightCoral       ", RGB(255,135,135)   },
	/*211*/  {  "PaleVioletRed1   ", RGB(255,135,175)   },
	/*212*/  {  "Orchid2          ", RGB(255,135,215)   },
	/*213*/  {  "Orchid1          ", RGB(255,135,255)   },
	/*214*/  {  "Orange1          ", RGB(255,175,0)     },
	/*215*/  {  "SandyBrown       ", RGB(255,175,95)    },
	/*216*/  {  "LightSalmon1     ", RGB(255,175,135)   },
	/*217*/  {  "LightPink1       ", RGB(255,175,175)   },
	/*218*/  {  "Pink1            ", RGB(255,175,215)   },
	/*219*/  {  "Plum1            ", RGB(255,175,255)   },
	/*220*/  {  "Gold1            ", RGB(255,215,0)     },
	/*221*/  {  "LightGoldenrod2  ", RGB(255,215,95)    },
	/*222*/  {  "LightGoldenrod2  ", RGB(255,215,135)   },
	/*223*/  {  "NavajoWhite1     ", RGB(255,215,175)   },
	/*224*/  {  "MistyRose1       ", RGB(255,215,215)   },
	/*225*/  {  "Thistle1         ", RGB(255,215,255)   },
	/*226*/  {  "Yellow1          ", RGB(255,255,0)     },
	/*227*/  {  "LightGoldenrod1  ", RGB(255,255,95)    },
	/*228*/  {  "Khaki1           ", RGB(255,255,135)   },
	/*229*/  {  "Wheat1           ", RGB(255,255,175)   },
	/*230*/  {  "Cornsilk1        ", RGB(255,255,215)   },
	/*231*/  {  "Grey100          ", RGB(255,255,255)   },
	/*232*/  {  "Grey3            ", RGB(8,8,8)         },
	/*233*/  {  "Grey7            ", RGB(18,18,18)      },
	/*234*/  {  "Grey11           ", RGB(28,28,28)      },
	/*235*/  {  "Grey15           ", RGB(38,38,38)      },
	/*236*/  {  "Grey19           ", RGB(48,48,48)      },
	/*237*/  {  "Grey23           ", RGB(58,58,58)      },
	/*238*/  {  "Grey27           ", RGB(68,68,68)      },
	/*239*/  {  "Grey30           ", RGB(78,78,78)      },
	/*240*/  {  "Grey35           ", RGB(88,88,88)      },
	/*241*/  {  "Grey39           ", RGB(98,98,98)      },
	/*242*/  {  "Grey42           ", RGB(108,108,108)   },
	/*243*/  {  "Grey46           ", RGB(118,118,118)   },
	/*244*/  {  "Grey50           ", RGB(128,128,128)   },
	/*245*/  {  "Grey54           ", RGB(138,138,138)   },
	/*246*/  {  "Grey58           ", RGB(148,148,148)   },
	/*247*/  {  "Grey62           ", RGB(158,158,158)   },
	/*248*/  {  "Grey66           ", RGB(168,168,168)   },
	/*249*/  {  "Grey70           ", RGB(178,178,178)   },
	/*250*/  {  "Grey74           ", RGB(188,188,188)   },
	/*251*/  {  "Grey78           ", RGB(198,198,198)   },
	/*252*/  {  "Grey82           ", RGB(208,208,208)   },
	/*253*/  {  "Grey85           ", RGB(218,218,218)   },
	/*254*/  {  "Grey89           ", RGB(228,228,228)   },
	/*255*/  {  "Grey93           ", RGB(238,238,238)   },
};

#endif  /*XTERMDEFS_H_INCLUDED*/
/*end*/
