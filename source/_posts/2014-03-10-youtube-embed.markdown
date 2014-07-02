---
layout: post
title: "YouTube Embed Code Generator"
date: 2014-03-10 17:20:52 +0100
comments: true
categories: [Code, Tools, Internet]
---

<script>
function generate() {
	var hlink = document.getElementById("url").value;
	if (hlink != "") {
		var boom = hlink.split("?v=");
		if (boom[1] == null) {
			document.getElementById("code").value = "Invalid URL";
		} else {
			hlink = "//www.youtube.com/embed/" + boom[1] + "?hl=hu_HU&hd=1&vq=hd720&rel=0&showinfo=0&modestbranding=0&autohide=1&showsearch=0&version=3&fs=1&iv_load_policy=3";
			if (document.getElementById("fill").checked) {
				var embedcode = "<iframe src=\"" + hlink + "\" width=\"100%\" height=\"410\" frameborder=\"0\" allowfullscreen></iframe>";
			} else {
				var embedcode = "<iframe src=\"" + hlink + "\" width=\"730\" height=\"410\" frameborder=\"0\" allowfullscreen></iframe>";
			}
			document.getElementById("code").value = embedcode;
			document.getElementById("code").select();
		}
	}
}
</script>

<center><input style="line-height:160p%;padding:3px 6px" type="url" id="url" size="50" autofocus onkeypress="if (event.keyCode == 13) document.getElementById('btn').click()" placeholder="Paste YouTube link here"/>
<input type="checkbox" id="fill" checked>Fill
<button style="height:28px;margin-top:5px;margin-bottom:8px;margin-left:10px;margin-right:10px" id="btn" onclick="generate();" class="generate">Generate</button><br>
<textarea style="resize:none;padding:3px 6px;margin-bottom:20px" placeholder="Your embed code will be here" id="code" cols="60" rows="5" wrap="hard"></textarea></center>

Tool to create HTML code to embed YouTube videos with the following characteristics:

- Auto loads 720p.
- Disables video suggestions at the end of the video.
- Disables title bar and other information.
- Annotations are disabled for peacefull experience.

---
