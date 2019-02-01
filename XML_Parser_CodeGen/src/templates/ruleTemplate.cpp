bool {{ RULE_NAME }}() {
{{ ATTRIBUTES }}
	if ({{ CONDITION }}) {
		return true; //Permit
	}
	else {
		return false; //Deny
	}
}
