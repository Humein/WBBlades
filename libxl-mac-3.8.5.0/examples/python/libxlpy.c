#include <Python.h>
#include <libxl.h>

extern PyTypeObject XLPyBookType;
extern PyTypeObject XLPySheetType;
extern PyTypeObject XLPyFormatType;
extern PyTypeObject XLPyFontType;

#define INIT_TYPE(Type) \
	Type.tp_new = PyType_GenericNew; \
	if (PyType_Ready(&Type) < 0) return; \
	Py_INCREF(&Type)

#define ADD_INT_CONSTANT(v) PyModule_AddIntConstant(mod, #v, v)
void initlibxlpy(void)
{
    PyObject* mod;
    mod = Py_InitModule3("libxlpy", NULL, "A libxl python wrapper");
    if (mod == NULL) return;
     
    // Init Classes
	INIT_TYPE(XLPyBookType);
    INIT_TYPE(XLPySheetType);
	INIT_TYPE(XLPyFormatType);
	INIT_TYPE(XLPyFontType);

    // Module's Public API
    PyModule_AddObject(mod, "Book", (PyObject* )&XLPyBookType);

	ADD_INT_CONSTANT(SHEETTYPE_SHEET);
	ADD_INT_CONSTANT(SHEETTYPE_CHART);
	ADD_INT_CONSTANT(SHEETTYPE_UNKNOWN);

	ADD_INT_CONSTANT(CELLTYPE_NUMBER);
	ADD_INT_CONSTANT(CELLTYPE_STRING);
	ADD_INT_CONSTANT(CELLTYPE_BOOLEAN);
	ADD_INT_CONSTANT(CELLTYPE_BLANK);
	ADD_INT_CONSTANT(CELLTYPE_ERROR);

	ADD_INT_CONSTANT(NUMFORMAT_GENERAL);
	ADD_INT_CONSTANT(NUMFORMAT_NUMBER);
	ADD_INT_CONSTANT(NUMFORMAT_NUMBER_D2);
	ADD_INT_CONSTANT(NUMFORMAT_NUMBER_SEP);
	ADD_INT_CONSTANT(NUMFORMAT_NUMBER_SEP_D2);
	ADD_INT_CONSTANT(NUMFORMAT_CURRENCY_NEGBRA);
	ADD_INT_CONSTANT(NUMFORMAT_CURRENCY_NEGBRARED);
	ADD_INT_CONSTANT(NUMFORMAT_CURRENCY_D2_NEGBRA);
	ADD_INT_CONSTANT(NUMFORMAT_CURRENCY_D2_NEGBRARED);
	ADD_INT_CONSTANT(NUMFORMAT_PERCENT);
	ADD_INT_CONSTANT(NUMFORMAT_PERCENT_D2);
	ADD_INT_CONSTANT(NUMFORMAT_SCIENTIFIC_D2);
	ADD_INT_CONSTANT(NUMFORMAT_FRACTION_ONEDIG);
	ADD_INT_CONSTANT(NUMFORMAT_FRACTION_TWODIG);
	ADD_INT_CONSTANT(NUMFORMAT_DATE);
	ADD_INT_CONSTANT(NUMFORMAT_CUSTOM_D_MON_YY);
	ADD_INT_CONSTANT(NUMFORMAT_CUSTOM_D_MON);
	ADD_INT_CONSTANT(NUMFORMAT_CUSTOM_MON_YY);
	ADD_INT_CONSTANT(NUMFORMAT_CUSTOM_HMM_AM);
	ADD_INT_CONSTANT(NUMFORMAT_CUSTOM_HMMSS_AM);
	ADD_INT_CONSTANT(NUMFORMAT_CUSTOM_HMM);
	ADD_INT_CONSTANT(NUMFORMAT_CUSTOM_HMMSS);
	ADD_INT_CONSTANT(NUMFORMAT_CUSTOM_MDYYYY_HMM);
	ADD_INT_CONSTANT(NUMFORMAT_NUMBER_SEP_NEGBRA);
	ADD_INT_CONSTANT(NUMFORMAT_NUMBER_SEP_NEGBRARED);
	ADD_INT_CONSTANT(NUMFORMAT_NUMBER_D2_SEP_NEGBRA);
	ADD_INT_CONSTANT(NUMFORMAT_NUMBER_D2_SEP_NEGBRARED);
	ADD_INT_CONSTANT(NUMFORMAT_ACCOUNT);
	ADD_INT_CONSTANT(NUMFORMAT_ACCOUNTCUR);
	ADD_INT_CONSTANT(NUMFORMAT_ACCOUNT_D2);
	ADD_INT_CONSTANT(NUMFORMAT_ACCOUNT_D2_CUR);
	ADD_INT_CONSTANT(NUMFORMAT_CUSTOM_MMSS);
	ADD_INT_CONSTANT(NUMFORMAT_CUSTOM_H0MMSS);
	ADD_INT_CONSTANT(NUMFORMAT_CUSTOM_MMSS0);
	ADD_INT_CONSTANT(NUMFORMAT_CUSTOM_000P0E_PLUS0);
	ADD_INT_CONSTANT(NUMFORMAT_TEXT);

    ADD_INT_CONSTANT(ERRORTYPE_NULL);
    ADD_INT_CONSTANT(ERRORTYPE_DIV_0);
    ADD_INT_CONSTANT(ERRORTYPE_VALUE);
    ADD_INT_CONSTANT(ERRORTYPE_REF);
    ADD_INT_CONSTANT(ERRORTYPE_NAME);
    ADD_INT_CONSTANT(ERRORTYPE_NUM);
    ADD_INT_CONSTANT(ERRORTYPE_NA);
    // Available on doc but not on libxl.h
    PyModule_AddIntConstant(mod, "ERRORTYPE_NOERROR", 0xff); 

    ADD_INT_CONSTANT(SHEETSTATE_VISIBLE);
    ADD_INT_CONSTANT(SHEETSTATE_HIDDEN);
    ADD_INT_CONSTANT(SHEETSTATE_VERYHIDDEN);

    ADD_INT_CONSTANT(PAPER_DEFAULT);
    ADD_INT_CONSTANT(PAPER_LETTER);
    ADD_INT_CONSTANT(PAPER_LETTERSMALL);
    ADD_INT_CONSTANT(PAPER_TABLOID);
    ADD_INT_CONSTANT(PAPER_LEDGER);
    ADD_INT_CONSTANT(PAPER_LEGAL);
    ADD_INT_CONSTANT(PAPER_STATEMENT);
    ADD_INT_CONSTANT(PAPER_EXECUTIVE);
    ADD_INT_CONSTANT(PAPER_A3);
    ADD_INT_CONSTANT(PAPER_A4);
    ADD_INT_CONSTANT(PAPER_A4SMALL);
    ADD_INT_CONSTANT(PAPER_A5);
    ADD_INT_CONSTANT(PAPER_B4);
    ADD_INT_CONSTANT(PAPER_B5);
    ADD_INT_CONSTANT(PAPER_FOLIO);
    ADD_INT_CONSTANT(PAPER_QUATRO);
    ADD_INT_CONSTANT(PAPER_10x14);
    ADD_INT_CONSTANT(PAPER_10x17);
    ADD_INT_CONSTANT(PAPER_NOTE);
    ADD_INT_CONSTANT(PAPER_ENVELOPE_9);
    ADD_INT_CONSTANT(PAPER_ENVELOPE_10);
    ADD_INT_CONSTANT(PAPER_ENVELOPE_11);
    ADD_INT_CONSTANT(PAPER_ENVELOPE_12);
    ADD_INT_CONSTANT(PAPER_ENVELOPE_14);
    ADD_INT_CONSTANT(PAPER_C_SIZE);
    ADD_INT_CONSTANT(PAPER_D_SIZE);
    ADD_INT_CONSTANT(PAPER_E_SIZE);
    ADD_INT_CONSTANT(PAPER_ENVELOPE_DL);
    ADD_INT_CONSTANT(PAPER_ENVELOPE_C5);
    ADD_INT_CONSTANT(PAPER_ENVELOPE_C3);
    ADD_INT_CONSTANT(PAPER_ENVELOPE_C4);
    ADD_INT_CONSTANT(PAPER_ENVELOPE_C6);
    ADD_INT_CONSTANT(PAPER_ENVELOPE_C65);
    ADD_INT_CONSTANT(PAPER_ENVELOPE_B4);
    ADD_INT_CONSTANT(PAPER_ENVELOPE_B5);
    ADD_INT_CONSTANT(PAPER_ENVELOPE_B6);
    ADD_INT_CONSTANT(PAPER_ENVELOPE);
    ADD_INT_CONSTANT(PAPER_ENVELOPE_MONARCH);
    ADD_INT_CONSTANT(PAPER_US_ENVELOPE);
    ADD_INT_CONSTANT(PAPER_FANFOLD);
    ADD_INT_CONSTANT(PAPER_GERMAN_STD_FANFOLD);
    ADD_INT_CONSTANT(PAPER_GERMAN_LEGAL_FANFOLD);

    ADD_INT_CONSTANT(ALIGNH_GENERAL);
    ADD_INT_CONSTANT(ALIGNH_LEFT);
    ADD_INT_CONSTANT(ALIGNH_CENTER);
    ADD_INT_CONSTANT(ALIGNH_RIGHT);
    ADD_INT_CONSTANT(ALIGNH_FILL);
    ADD_INT_CONSTANT(ALIGNH_JUSTIFY);
    ADD_INT_CONSTANT(ALIGNH_MERGE);
    ADD_INT_CONSTANT(ALIGNH_DISTRIBUTED);

    ADD_INT_CONSTANT(ALIGNV_TOP);
    ADD_INT_CONSTANT(ALIGNV_CENTER);
    ADD_INT_CONSTANT(ALIGNV_BOTTOM);
    ADD_INT_CONSTANT(ALIGNV_JUSTIFY);
    ADD_INT_CONSTANT(ALIGNV_DISTRIBUTED);

    ADD_INT_CONSTANT(BORDERSTYLE_NONE);
    ADD_INT_CONSTANT(BORDERSTYLE_THIN);
    ADD_INT_CONSTANT(BORDERSTYLE_MEDIUM);
    ADD_INT_CONSTANT(BORDERSTYLE_DASHED);
    ADD_INT_CONSTANT(BORDERSTYLE_DOTTED);
    ADD_INT_CONSTANT(BORDERSTYLE_THICK);
    ADD_INT_CONSTANT(BORDERSTYLE_DOUBLE);
    ADD_INT_CONSTANT(BORDERSTYLE_HAIR);
    ADD_INT_CONSTANT(BORDERSTYLE_MEDIUMDASHED);
    ADD_INT_CONSTANT(BORDERSTYLE_DASHDOT);
    ADD_INT_CONSTANT(BORDERSTYLE_MEDIUMDASHDOT);
    ADD_INT_CONSTANT(BORDERSTYLE_DASHDOTDOT);
    ADD_INT_CONSTANT(BORDERSTYLE_MEDIUMDASHDOTDOT);
    ADD_INT_CONSTANT(BORDERSTYLE_SLANTDASHDOT);

    ADD_INT_CONSTANT(BORDERDIAGONAL_NONE);
    ADD_INT_CONSTANT(BORDERDIAGONAL_DOWN);
    ADD_INT_CONSTANT(BORDERDIAGONAL_UP);
    ADD_INT_CONSTANT(BORDERDIAGONAL_BOTH);

    ADD_INT_CONSTANT(COLOR_BLACK);
    ADD_INT_CONSTANT(COLOR_WHITE);
    ADD_INT_CONSTANT(COLOR_RED);
    ADD_INT_CONSTANT(COLOR_BRIGHTGREEN);
    ADD_INT_CONSTANT(COLOR_BLUE);
    ADD_INT_CONSTANT(COLOR_YELLOW);
    ADD_INT_CONSTANT(COLOR_PINK);
    ADD_INT_CONSTANT(COLOR_TURQUOISE);
    ADD_INT_CONSTANT(COLOR_DARKRED);
    ADD_INT_CONSTANT(COLOR_GREEN);
    ADD_INT_CONSTANT(COLOR_DARKBLUE);
    ADD_INT_CONSTANT(COLOR_DARKYELLOW);
    ADD_INT_CONSTANT(COLOR_VIOLET);
    ADD_INT_CONSTANT(COLOR_TEAL);
    ADD_INT_CONSTANT(COLOR_GRAY25);
    ADD_INT_CONSTANT(COLOR_GRAY50);
    ADD_INT_CONSTANT(COLOR_PERIWINKLE_CF);
    ADD_INT_CONSTANT(COLOR_PLUM_CF);
    ADD_INT_CONSTANT(COLOR_IVORY_CF);
    ADD_INT_CONSTANT(COLOR_LIGHTTURQUOISE_CF);
    ADD_INT_CONSTANT(COLOR_DARKPURPLE_CF);
    ADD_INT_CONSTANT(COLOR_CORAL_CF);
    ADD_INT_CONSTANT(COLOR_OCEANBLUE_CF);
    ADD_INT_CONSTANT(COLOR_ICEBLUE_CF);
    ADD_INT_CONSTANT(COLOR_DARKBLUE_CL);
    ADD_INT_CONSTANT(COLOR_PINK_CL);
    ADD_INT_CONSTANT(COLOR_YELLOW_CL);
    ADD_INT_CONSTANT(COLOR_TURQUOISE_CL);
    ADD_INT_CONSTANT(COLOR_VIOLET_CL);
    ADD_INT_CONSTANT(COLOR_DARKRED_CL);
    ADD_INT_CONSTANT(COLOR_TEAL_CL);
    ADD_INT_CONSTANT(COLOR_BLUE_CL);
    ADD_INT_CONSTANT(COLOR_SKYBLUE);
    ADD_INT_CONSTANT(COLOR_LIGHTTURQUOISE);
    ADD_INT_CONSTANT(COLOR_LIGHTGREEN);
    ADD_INT_CONSTANT(COLOR_LIGHTYELLOW);
    ADD_INT_CONSTANT(COLOR_PALEBLUE);
    ADD_INT_CONSTANT(COLOR_ROSE);
    ADD_INT_CONSTANT(COLOR_LAVENDER);
    ADD_INT_CONSTANT(COLOR_TAN);
    ADD_INT_CONSTANT(COLOR_LIGHTBLUE);
    ADD_INT_CONSTANT(COLOR_AQUA);
    ADD_INT_CONSTANT(COLOR_LIME);
    ADD_INT_CONSTANT(COLOR_GOLD);
    ADD_INT_CONSTANT(COLOR_LIGHTORANGE);
    ADD_INT_CONSTANT(COLOR_ORANGE);
    ADD_INT_CONSTANT(COLOR_BLUEGRAY);
    ADD_INT_CONSTANT(COLOR_GRAY40);
    ADD_INT_CONSTANT(COLOR_DARKTEAL);
    ADD_INT_CONSTANT(COLOR_SEAGREEN);
    ADD_INT_CONSTANT(COLOR_DARKGREEN);
    ADD_INT_CONSTANT(COLOR_OLIVEGREEN);
    ADD_INT_CONSTANT(COLOR_BROWN);
    ADD_INT_CONSTANT(COLOR_PLUM);
    ADD_INT_CONSTANT(COLOR_INDIGO);
    ADD_INT_CONSTANT(COLOR_GRAY80);
    ADD_INT_CONSTANT(COLOR_DEFAULT_FOREGROUND);
    ADD_INT_CONSTANT(COLOR_DEFAULT_BACKGROUND);
    ADD_INT_CONSTANT(COLOR_TOOLTIP);
    ADD_INT_CONSTANT(COLOR_AUTO);

    ADD_INT_CONSTANT(FILLPATTERN_NONE);
    ADD_INT_CONSTANT(FILLPATTERN_SOLID);
    ADD_INT_CONSTANT(FILLPATTERN_GRAY50);
    ADD_INT_CONSTANT(FILLPATTERN_GRAY75);
    ADD_INT_CONSTANT(FILLPATTERN_GRAY25);
    ADD_INT_CONSTANT(FILLPATTERN_HORSTRIPE);
    ADD_INT_CONSTANT(FILLPATTERN_VERSTRIPE);
    ADD_INT_CONSTANT(FILLPATTERN_REVDIAGSTRIPE);
    ADD_INT_CONSTANT(FILLPATTERN_DIAGSTRIPE);
    ADD_INT_CONSTANT(FILLPATTERN_DIAGCROSSHATCH);
    ADD_INT_CONSTANT(FILLPATTERN_THICKDIAGCROSSHATCH);
    ADD_INT_CONSTANT(FILLPATTERN_THINHORSTRIPE);
    ADD_INT_CONSTANT(FILLPATTERN_THINVERSTRIPE);
    ADD_INT_CONSTANT(FILLPATTERN_THINREVDIAGSTRIPE);
    ADD_INT_CONSTANT(FILLPATTERN_THINDIAGSTRIPE);
    ADD_INT_CONSTANT(FILLPATTERN_THINHORCROSSHATCH);
    ADD_INT_CONSTANT(FILLPATTERN_THINDIAGCROSSHATCH);
    ADD_INT_CONSTANT(FILLPATTERN_GRAY12P5);
    ADD_INT_CONSTANT(FILLPATTERN_GRAY6P25);

}