#include "stdafx.h"
#include "xrManagedUILib.h"

using namespace XRay;
using namespace XRay::xrManagedUILib;

XRay::xrManagedUILib::UIXMLParser::UIXMLParser() : NativeParserObject(new CUIXml())
{
}

XRay::xrManagedUILib::UIXMLParser::~UIXMLParser()
{
	delete NativeParserObject;
}

Test::Test()
{
	CUIXml xml;
	xml.Load(CONFIG_PATH, UI_PATH, "ui_mm_loading_screen.xml");

	XML_NODE* pNode = xml.GetRoot()->FirstChild();
	while (pNode)
	{
		Log::Info(gcnew String(pNode->Value()));
		pNode = pNode->NextSibling();
	}
}

Test::~Test()
{

}