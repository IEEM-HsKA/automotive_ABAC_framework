{%- for ATTRIBUTE in attributes %}	const Attribute {{ ATTRIBUTE.Name }}({{ ATTRIBUTE.ID_Hash }}, {{ ATTRIBUTE.Value_Hash }}, {{ ATTRIBUTE.Category }});
{% endfor -%}
