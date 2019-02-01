import re as re
import hashlib

class parseXACML:
    root = 0
    ns = 0
    def __init__(self, XML_Root, Namespace):
        self.root = XML_Root
        self.ns = Namespace
          
    def getPolicyID(self):
        PolicyId = re.search('\w+$', self.root.get('PolicyId'))
        PolicyId = PolicyId.group(0)
        return PolicyId
    
    def getRuleID(self):
        for rule in self.root.findall('xacmlTag:Rule',self.ns):
            RuleId = re.search('\w+$', rule.get('RuleId'))
            RuleId = RuleId.group(0)
        return RuleId
    
    def getTargetAttributes(self):
        Attributes = []
        #Get Target Attributes
        PolicyId = re.search('\w+$', self.root.get('PolicyId'))
        PolicyId = PolicyId.group(0)
    #     print("PolicyId: ", PolicyId)
            
            
        for target in self.root.findall('xacmlTag:Target/xacmlTag:AnyOf/xacmlTag:AllOf/xacmlTag:Match',self.ns):
            MatchId = re.search('(?<=function:).*', target.get('MatchId'))
            MatchId = MatchId.group(0)
    #         print("->>>>POLICY TARGET<<<<<---")
    #         print("MatchId: ", MatchId)
            
    
            #Get AttributeID
            for Match in target.findall('xacmlTag:AttributeDesignator',self.ns):
                AttributeID = Match.get('AttributeId')
                AttributeID_hash = hashlib.md5(Match.get('AttributeId').encode('utf-8')).hexdigest()[:4].upper()
    #             print("AttributeId: ", Match.get('AttributeId'))
            
    
            #Get AttributeValue
            for Match in target.findall('xacmlTag:AttributeValue',self.ns):
                AttributeValue = Match.text
                AttributeValue_hash = hashlib.md5(Match.text.encode('utf-8')).hexdigest()[:4].upper()
    #             print("AttributeValue: ", Match.text, "Hash: ", hash)
            
            #Get AttributeCategory    
            for Match in target.findall('xacmlTag:AttributeDesignator',self.ns):
                Category = re.search('(?<=subject-category:).*', Match.get('Category'))
                Category = Category.group(0)
                Category = Category.replace('access-subject','ACCESS_SUBJECT')
    #             print("Category: ", Category)
                  
            for Match in target.findall('xacmlTag:AttributeDesignator',self.ns):
                DataType = re.search('(?<=XMLSchema#).*', Match.get('DataType'))
                DataType = DataType.group(0)
    #             print("DataType: ", DataType)        
            Attributes.append({'Name' : AttributeID + "_" + AttributeValue, 'ID_String' : AttributeID,'ID_Hash' : "0x" + AttributeID_hash, 'Value_Hash' : "0x" + AttributeValue_hash,'Category' : Category})
        return Attributes
           
    def getRuleAttributes(self):
        Attributes = []
        #Get Rule Attributes
        for rule in self.root.findall('xacmlTag:Rule',self.ns):
#             Effect = rule.get('Effect')
            RuleId = re.search('\w+$', rule.get('RuleId'))
            RuleId = RuleId.group(0)
    #         print("->>>>RULE TARGET<<<<<---")
    #         print("Effect: ", Effect)
    #         print("RuleId: ", RuleId)
     
            for target in rule.findall('xacmlTag:Target/xacmlTag:AnyOf/xacmlTag:AllOf/xacmlTag:Match',self.ns):
                MatchId = re.search('(?<=function:).*', target.get('MatchId'))
                MatchId = MatchId.group(0)
    #             print("MatchId: ", MatchId)
            
            
                #Get AttributeID
                for Match in target.findall('xacmlTag:AttributeDesignator',self.ns):
                    AttributeID = Match.get('AttributeId')
                    AttributeID_hash = hashlib.md5(Match.get('AttributeId').encode('utf-8')).hexdigest()[:4].upper()
    #                 print("AttributeId: ", Match.get('AttributeId'))
    
                #Get AttributeValue
                for Match in target.findall('xacmlTag:AttributeValue',self.ns):
                    AttributeValue = Match.text
                    AttributeValue_hash = hashlib.md5(Match.text.encode('utf-8')).hexdigest()[:4].upper()
    #                 print("AttributeValue: ",Match.text)
                       
                #Get AttributeCategory       
                for Match in target.findall('xacmlTag:AttributeDesignator',self.ns):
                    Category = re.search('(?<=attribute-category:).*', Match.get('Category'))
                    Category = Category.group(0)
    #                 print("Category: ", Category)
                    
                for Match in target.findall('xacmlTag:AttributeDesignator',self.ns):
                    DataType = re.search('(?<=XMLSchema#).*', Match.get('DataType'))
                    DataType = DataType.group(0)
    #                 print("DataType: ", DataType)     
    #             print("->>>>RULE TARGET<<<<<---")
                Attributes.append({'Name' : AttributeID + "_" + AttributeValue, 'ID_String' : AttributeID,'ID_Hash' : "0x" + AttributeID_hash, 'Value_Hash' : "0x" + AttributeValue_hash,'Category' : Category.upper()})
        return Attributes
        
        