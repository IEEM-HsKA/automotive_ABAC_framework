Decision {{ POLICY_NAME }}() {
{{ ATTRIBUTES }}
	if ({{ CONDITION }}) {
		if ({{ RULE_NAME }}()) {
			return PERMIT;
		}
		else {
			return DENY;
		}
	}
	else {
		return NOT_APPLICABLE;
	}
	return NOT_APPLICABLE;
}
