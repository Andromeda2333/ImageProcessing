class MyClass(object):
    '''
    classdocs
    '''
    def __init__(self, step):
        '''
        Constructor
        '''
        self.step=step
        
    def next(self):
        if self.step==0:
            raise StopIteration
        self.step-=1
        return self.step
        
    def __iter__(self):
        return self
    