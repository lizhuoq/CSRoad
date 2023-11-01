def tag(name, *content, cls=None, **attrs):
    """
    >>> tag('br')
    '<br />'
    >>> tag('p', 'hello')
    '<p>hello</p>'
    >>> print(tag('p', 'hello', 'world'))
    <p>hello</p>
    <p>world</p>
    >>> tag('p', 'hello', id=33)
    '<p id="33">hello</p>'
    >>> print(tag('p', 'hello', 'world', cls='sidebar'))
    <p class="sidebar">hello</p>
    <p class="sidebar">world</p>
    >>> tag(content='testing', name='img')
    '<img content="testing" />'
    >>> my_tag = {'name': 'img', 'title': 'Sunset', 'src': 'sunset.jpg', 'cls': 'framed'}
    >>> tag(**my_tag)
    '<img class="framed" src="sunset.jpg" title="Sunset" />'
    """
    if cls is not None:
        attrs['class'] = cls
    if attrs:
        attr_str = ''.join(' %s="%s"' % (attr, value) for attr, value in sorted(attrs.items()))
    else:
        attr_str = ''
    if content:
        return '\n'.join('<%s%s>%s</%s>' % (name, attr_str, c, name) for c in content)
    else:
        return '<%s%s />' % (name, attr_str)


if __name__ == '__main__':
    import doctest
    doctest.testmod()