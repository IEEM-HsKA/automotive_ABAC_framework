from jinja2 import Template
from jinja2 import Environment, FileSystemLoader
import re as re

def generateCode(_policyID,_ruleID,_targetAttributes,_ruleAttributes):
    env = Environment(loader=FileSystemLoader('templates'))
    attributeTemplate = env.get_template('attributeTemplate.cpp')
    ruleTemplate = env.get_template('ruleTemplate.cpp')
    policyTemplate = env.get_template('policyTemplate.cpp')
    policiesClassTemplate = env.get_template('policiesClassTemplate.cpp')
    
    roleAttributes = attributeTemplate.render(attributes = _targetAttributes)
    ruleAttributes = attributeTemplate.render(attributes = _ruleAttributes)
    
    
    localEvironment = ""
    localEvironmentAttr = ""
    mEvironment = ""
    
    roleList = []
    for item in _targetAttributes:
        roleList.append(item['Name'] + ' == ' + 'mAccessSubject')
        
    roleCondition = ''
    for role in roleList:
        roleCondition = roleCondition + role + ' || '  
    roleCondition = re.sub('\s\|\|\s+$','', roleCondition)
    
    
    ruleAttrList = []
    for item in _ruleAttributes:
        ruleAttrList.append(item['Name'] + ' == ' + "m" + item['ID_String'][0].upper() + item['ID_String'][1:])
        if item['Category'] == "ENVIRONMENT":
            localEvironment = item['Name']
            localEvironmentAttr = item['Name'] + "(" + item['ID_Hash'] + "," + item['Value_Hash'] + "," + item['Category'] + ")"
            mEvironment = "m" + item['ID_String'][0].upper() + item['ID_String'][1:]
    ruleCondition = ''
    for ruleAttr in ruleAttrList:
        ruleCondition = ruleCondition + ruleAttr + ' && '  
    ruleCondition = re.sub(' &&\s+$','', ruleCondition)
    
    ruleFunction = ruleTemplate.render(RULE_NAME = _ruleID, ATTRIBUTES = ruleAttributes, CONDITION = ruleCondition)
    policyFunction = policyTemplate.render(POLICY_NAME = _policyID, RULE_NAME = _ruleID, ATTRIBUTES = roleAttributes, CONDITION = roleCondition)
    policiesClassTemplate = policiesClassTemplate.render(POLICIES = policyFunction, RULES = ruleFunction, 
                                                         POLICY_NAME = _policyID, MEMBER_ENVIROMENT = mEvironment, 
                                                         LOCAL_ENVIROMENT_ATTR = localEvironmentAttr, LOCAL_ENVIROMENT = localEvironment)
    print(roleCondition)
    print(ruleCondition)
    print(roleAttributes)
    print(ruleAttributes)
    print(ruleFunction)
    print(policyFunction)
    print(policiesClassTemplate)
#     print(ruleTemplate.render(ATTRIBUTES = attributes, RULE_NAME = ruleID))
