class SocExplorerRegister:
	plugin=0
	address=0
	def __init__(self, plugin,address):
		self.plugin = plugin
		self.address = address
	def value(self):
		return self.plugin.Read(self.address,1)[0]
	def set(self, value):
		return self.plugin.Write(self.address,[value])
