import xml.etree.ElementTree as ET

from function import parseXACML
from codeGenerator import generateCode
from tkinter import filedialog
from tkinter import *


ns = {'xacmlTag' : 'urn:oasis:names:tc:xacml:3.0:core:schema:wd-17'}

TkFileDialog = Tk()
  
TkFileDialog.filename = filedialog.askopenfilename(filetypes=[("XML File",".xml")],title="Open XML file")


if TkFileDialog.filename != '':
    tree = ET.parse(TkFileDialog.filename)
    # tree = ET.parse('com.hska.diagnosis.mechanicCanAccessDiagnosisData.xml')
    # tree = ET.parse('test.xml')
    root = tree.getroot()
    parserObj = parseXACML(root,ns)
    
    targetAttributes = parserObj.getTargetAttributes()
    ruleAttributes = parserObj.getRuleAttributes()
    policyID = parserObj.getPolicyID()
    ruleID = parserObj.getRuleID()
    generateCode(policyID,ruleID,targetAttributes,ruleAttributes)
    
else:
    print("No file selected")
    