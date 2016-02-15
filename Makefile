.PHONY: clean All

All:
	@echo "----------Building project:[ ARDELVEmk7013 - Debug ]----------"
	@cd "ARDELVEmk7013" && "$(MAKE)" -f  "ARDELVEmk7013.mk"
clean:
	@echo "----------Cleaning project:[ ARDELVEmk7013 - Debug ]----------"
	@cd "ARDELVEmk7013" && "$(MAKE)" -f  "ARDELVEmk7013.mk" clean
